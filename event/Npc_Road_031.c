-------- EventFlow: Npc_Road_031 --------

Actor: Npc_Road_031
entrypoint: None()
actions: ['Demo_Talk', 'Demo_TalkASync']
queries: ['IsRest', 'IsOnInstEventFlag', 'CheckActorAction13']
params: {'CreateMode': 0, 'IsGrounding': False, 'IsWorld': False, 'PosX': 0.0, 'PosY': 0.0, 'PosZ': 0.0, 'RotX': 0.0, 'RotY': 0.0, 'RotZ': 0.0}

Actor: EventSystemActor
entrypoint: None()
actions: ['Demo_ExitEventPlayer', 'Demo_FlagON']
queries: ['CheckTimeType', 'GeneralChoice3', 'CheckFlag']
params: {'CreateMode': 0, 'IsGrounding': False, 'IsWorld': False, 'PosX': 0.0, 'PosY': 0.0, 'PosZ': 0.0, 'RotX': 0.0, 'RotY': 0.0, 'RotZ': 0.0}

void Talk() {

    call Npc_Road_Common.InitTalk_Npc_Road_Common({'Self': ActorIdentifier(name="Npc_Road_031"), 'Flag': 'Npc_Road_031_CookReward'})

}

void Near() {
    switch EventSystemActor.CheckTimeType() {
      case 0:
        Event10:
        Npc_Road_031.Demo_TalkASync({'IsWaitFinish': True, 'DispFrame': 90, 'IsChecked': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:Near00'})
      case 1:
        goto Event10
      case 2:
        Event11:
        Npc_Road_031.Demo_TalkASync({'IsWaitFinish': True, 'DispFrame': 90, 'IsChecked': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:Near01'})
      case 3:
        goto Event11
      case 4:
        Event12:
        Npc_Road_031.Demo_TalkASync({'IsWaitFinish': True, 'DispFrame': 90, 'IsChecked': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:Near02'})
      case 5:
        goto Event12
      case 6:
        Event13:
        Npc_Road_031.Demo_TalkASync({'IsWaitFinish': True, 'DispFrame': 90, 'IsChecked': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:Near03'})
      case 7:
        goto Event13
    }
}

void MSG_Gerud_00() {

    call Rest()

    Event82:
    if Npc_Road_031.IsOnInstEventFlag() {
        Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:MSG_Gerud_00_1'})
        Event33:
        Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'IsCloseMessageDialog': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:Talk01'})
        Event27:
        switch EventSystemActor.GeneralChoice3() {
          case 0:

            call Yorozuya_Kaiwa.Yorozuya_Kounyu_Rain({'Self2': ActorIdentifier(name="Npc_Road_031")})

            Event41:
            Npc_Road_031.Demo_Talk({'IsCloseMessageDialog': False, 'IsWaitFinish': True, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:Talk02'})
            goto Event27
          case 1:

            call Yorozuya_Kaiwa.Yorozuya_Kaitori({'Self': ActorIdentifier(name="Npc_Road_031")})

            goto Event41
          case 2:
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'IsCloseMessageDialog': True, 'MessageId': 'EventFlowMsg/Npc_Road_031:GoodBye00'})
            EventSystemActor.Demo_ExitEventPlayer({'IsWaitFinish': True})
        }
    } else {
        Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:MSG_Gerud_00'})
        goto Event33
    }
}

void RetMSG_Gerud_00() {

    call Rest()

    switch Npc_Road_031.CheckActorAction13() {
      case 0:
        goto Event82
      case 1:
        goto Event82
      case 2:
        Event87:
        if Npc_Road_031.IsOnInstEventFlag() {
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:RetMSG_Gerud_00_1'})
            goto Event33
        } else {
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:RetMSG_Gerud_00'})
            goto Event33
        }
      case 3:
        goto Event87
      case 4:
        goto Event87
      case 5:
        goto Event87
      case 6:
        goto Event87
      case 7:
        goto Event87
      case 8:
        goto Event87
      case 9:
        goto Event87
      case 10:
        goto Event87
      case 11:
        goto Event87
      case 12:
        goto Event87
      case 13:
        goto Event87
    }
}

void MSG_Gerud_01() {

    call Rest()

    if Npc_Road_031.IsOnInstEventFlag() {
        Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:MSG_Gerud_01_1'})
        goto Event33
    } else {
        Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:MSG_Gerud_01'})
        goto Event33
    }
}

void RetMSG_Gerud_01() {

    call Rest()

    if Npc_Road_031.IsOnInstEventFlag() {
        Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:RetMSG_Gerud_01_1'})
        goto Event33
    } else {
        Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:RetMSG_Gerud_01'})
        goto Event33
    }
}

void MSG_Gerud_02() {

    call Rest()

    if Npc_Road_031.IsOnInstEventFlag() {
        Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:MSG_Gerud_02_1'})
        goto Event33
    } else {
        Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:MSG_Gerud_02'})
        goto Event33
    }
}

void RetMSG_Gerud_02() {

    call Rest()

    switch Npc_Road_031.CheckActorAction13() {
      case 0:
        Event84:
        if Npc_Road_031.IsOnInstEventFlag() {
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:RetMSG_Gerud_03_1'})
            goto Event33
        } else {
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:RetMSG_Gerud_03'})
            goto Event33
        }
      case 1:
        goto Event84
      case 2:
        Event85:
        if Npc_Road_031.IsOnInstEventFlag() {
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:RetMSG_Gerud_02_1'})
            goto Event33
        } else {
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:RetMSG_Gerud_02'})
            goto Event33
        }
      case 3:
        goto Event85
      case 4:
        goto Event84
      case 5:
        goto Event84
      case 6:
        goto Event84
      case 7:
        goto Event84
      case 8:
        goto Event84
      case 9:
        goto Event84
      case 10:
        goto Event84
      case 11:
        goto Event84
      case 12:
        goto Event84
      case 13:
        goto Event84
    }
}

void MSG_Gerud_03() {

    call Rest()

    switch Npc_Road_031.CheckActorAction13() {
      case 0:
        Event78:
        if Npc_Road_031.IsOnInstEventFlag() {
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:MSG_Gerud_04_1'})
            goto Event33
        } else {
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:MSG_Gerud_04'})
            goto Event33
        }
      case 1:
        goto Event78
      case 2:
        Event79:
        if Npc_Road_031.IsOnInstEventFlag() {
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:MSG_Gerud_03_1'})
            goto Event33
        } else {
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:MSG_Gerud_03'})
            goto Event33
        }
      case 3:
        goto Event79
      case 4:
        goto Event79
      case 5:
        goto Event79
      case 6:
        goto Event79
      case 7:
        goto Event79
      case 8:
        goto Event79
      case 9:
        goto Event79
      case 10:
        goto Event79
      case 11:
        goto Event79
      case 12:
        goto Event79
      case 13:
        goto Event79
    }
}

void RetMSG_Gerud_03() {

    call Rest()

    if Npc_Road_031.IsOnInstEventFlag() {
        Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:RetMSG_Gerud_04_1'})
        goto Event33
    } else {
        Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:RetMSG_Gerud_04'})
        goto Event33
    }
}

void Rest_End() {
    goto Event33
}

void Rest() {

    call InitTalk.InitTalk({'Arg_Turn': 0, 'Arg_Greeting': 'FollowAISchedule'})

    if EventSystemActor.CheckFlag({'FlagName': 'Npc_Road_031_First'}) {
        if Npc_Road_031.IsRest() {
            Event53:
            Npc_Road_031.Demo_Talk({'IsWaitFinish': True, 'IsCloseMessageDialog': False, 'ASName': '', 'IsBecomingSpeaker': True, 'IsOverWriteLabelActorName': False, 'MessageId': 'EventFlowMsg/Npc_Road_031:Rest_00'})
            EventSystemActor.Demo_FlagON({'FlagName': 'Npc_Road_031_First', 'IsWaitFinish': True})

            call Rest_End()

        }
    } else {
        goto Event53
    }
}