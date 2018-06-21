import ctypes
import struct
import pprint
import os
import json
import prod
import xml.etree.ElementTree as ET

files = [
('map_locations.js',''),
# ('map_locations_dungeon.js','_dungeon'),
# ('map_locations_trial.js','_trial'),
]

namefile = open('botw_names.json')
object_names = json.load(namefile)
namefile.close()

for outfilename,folder_suffix in files:

    objects = {}

    for filename in os.listdir('mubin'+folder_suffix):
        root = ET.parse('mubin'+folder_suffix+'/'+filename).getroot()

        dropactor_objs = (root.findall('./*/value') +
                          root.findall('./Rails/*/RailPoints/value'))

        # Build a list of actor instances that are excluded from the blood moon mechanism
        # (they will instead respawn immediately after reloading)
        off_wait_revival_actors = set()
        for actor in dropactor_objs:
            if 'LinkTag' not in actor.find('UnitConfigName').text:
                continue
            links = actor.findall('./LinksToObj/value')
            if not links:
                continue
            for link in links:
                link_type = link.find('DefinitionName').text
                if link_type == 'OffWaitRevival':
                    off_wait_revival_actors.add(link.get('DestUnitHashId'))

        for actor in dropactor_objs:
            data: dict = dict()
            data['file'] = filename.replace('.xml', '')

            name = actor.findall('./UnitConfigName')[0].text
            coords = [float(node.text[:-1]) for node in actor.findall('./Translate/value')]
            if len(coords) == 0:
                continue
            data['pos'] = [round(coords[0],2), round(coords[-1],2)]
            scale = [float(node.text[:-1]) for node in actor.findall('./Scale/value')]
            rotation = [float(node.text[:-1]) for node in actor.findall('./Rotate/value')]
            if len(rotation) == 0:
                if 'Rotate' in actor.attrib:
                    rotation = [0,float(actor.attrib['Rotate'][:-1]),0]
                else:
                    rotation = [0,0,0]
            drop_tables = actor.findall('./_Parameters/DropTable')
            drop_actors = (actor.findall('./_Parameters/DropActor') +
                           actor.findall('./_Parameters/RideHorseName') +
                           actor.findall('./_Parameters/EquipItem1') +
                           actor.findall('./_Parameters/EquipItem2') +
                           actor.findall('./_Parameters/EquipItem3') +
                           actor.findall('./_Parameters/EquipItem4') +
                           actor.findall('./_Parameters/EquipItem5') +
                           actor.findall('./_Parameters/ArrowName'))

            params = actor.find('_Parameters')
            is_hardmode = params != None and params.get('IsHardModeActor', False)

            if name in object_names:
                nice_name = object_names[name]
            else:
                nice_name = name

            if len(drop_tables):
                drop_table = drop_tables[0].text
                if drop_table != 'Normal':
                    name = name+':'+drop_table
                    nice_name = nice_name+':'+drop_table
            for drop_actor in drop_actors:
                if drop_actor.text in ('Normal', 'Default', 'NormalArrow'):
                    continue
                name += ':' + drop_actor.text
                nice_name += ':' + object_names[drop_actor.text]
            if is_hardmode:
                name = 'HARD:'+name
                nice_name = 'HARD:'+nice_name

            if ('Enemy_' in name or 'Weapon_' in name) and ('TBox_' not in name):
                level_sensor_mode = params != None and int(params.get('LevelSensorMode', 0))
                if level_sensor_mode < 1:
                    if 'Enemy_Giant_' in name:
                        name += ':NO_SCALING_ENEMY'
                        nice_name += ':No scaling (enemy)'
                    else:
                        name += ':NO_SCALING'
                        nice_name += ':No scaling'

            if 'Enemy_' in name:
                disable_rankup = params != None and bool(params.get('DisableRankUpForHardMode', False))
                if disable_rankup:
                    name += ':NO_RANKUP'
                    nice_name += ':No rankup'

            if 'Weapon_' in name:
                weapon_modifier = params != None and int(params.get('SharpWeaponJudgeType', 0))
                if weapon_modifier != 0:
                    name += ':MODIFIER_' + str(weapon_modifier)
                    nice_name += ':'
                    if weapon_modifier == 1:
                        nice_name += '⭐(random)'
                    if weapon_modifier == 2:
                        nice_name += '⭐'
                    if weapon_modifier == 3:
                        nice_name += '⭐⭐'

            actor_hash_id = actor.get('HashId')
            if actor_hash_id:
                data['hash_id'] = ctypes.c_uint32(int(actor_hash_id)).value
            else:
                data['hash_id'] = '???'

            if actor_hash_id in off_wait_revival_actors:
                name += ':OFF_WAIT_REVIVAL'
                nice_name += ':Always respawn'

            if name not in objects:
                objects[name] = {'display_name':nice_name, 'locations':[]}

            objects[name]['locations'].append(data)
            #if len(scale):
            #    objects[name]['locations'][-1].append({'width':scale[0],'height':scale[-1],'rotation':rotation[1]})

    for filename in os.listdir('blwp'+folder_suffix):
        f=open('blwp'+folder_suffix+'/'+filename,'rb')
        data = f.read()
        f.close()
        chunk_objects = prod.parseProd(data)
        for name in chunk_objects:
            if name in object_names:
                nice_name = object_names[name]
            else:
                nice_name = name
            if name not in objects:
                objects[name] = {'display_name':nice_name, 'locations':[]}
            objects[name]['locations'] += [(round(x,2),round(z,2)) for x,y,z in chunk_objects[name]]

    outfile = open(outfilename,'w')
    json.dump(objects, outfile, sort_keys=True,separators=(',', ':'))
    outfile.close()
