import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:shoulder_exercises/business_logic/phase_cubit/phase_state.dart';
import 'package:web_socket_channel/io.dart';

import '../../generated/assets.dart';
import '../../presentation/generated_data/Texts.dart';
import '../../presentation/phase_one/phase_one_screen.dart';
import '../../presentation/styles/colors.dart';

class PhaseCubit extends Cubit<PhaseState> {
  PhaseCubit() : super(PhaseInitial());

  static PhaseCubit get(context) => BlocProvider.of(context);

  final boardController = PageController();

  bool isLast = false;
  bool isFirst = true;

  bool ledStatus = false; //boolean value to track LED status, if its ON or OFF
  IOWebSocketChannel? channel;
  bool connected = false; //boolean value to track if WebSocket is connected
  String socketMessage = '';
  String rollMessage = '';
  String pitchMessage = '';
  String yawMessage = '';

  List<BoardingModel> phaseOne = [
    BoardingModel(
      image: Assets.refusedRefusedOne,
      title: Texts.exercies_refused_title,
      body: Texts.exercies_refused_Body,
      color: AppColor.error,
    ),
    BoardingModel(
      image: Assets.refusedRefusedTwo,
      title: Texts.exercies_refused_title,
      body: Texts.exercies_refused_Body,
      color: AppColor.error,
    ),
    BoardingModel(
      image: Assets.refusedRefusedThree,
      title: Texts.exercies_refused_title,
      body: Texts.exercies_refused_Body,
      color: AppColor.error,
    ),
    BoardingModel(
      image: Assets.refusedRefusedFour,
      title: Texts.exercies_refused_title,
      body: Texts.exercies_refused_Body,
      color: AppColor.error,
    ),
    BoardingModel(
      image: Assets.refusedRefusedFive,
      title: Texts.exercies_refused_title,
      body: Texts.exercies_refused_Body,
      color: AppColor.error,
    ),
    BoardingModel(
      image: Assets.phaseOneFirstExerciese,
      title: Texts.phase_one_exercies_one_title,
      body: Texts.phase_one_exercies_one_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneFirstExerciese,
      title: Texts.phase_one_exercies_two_title,
      body: Texts.phase_one_exercies_two_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneThirdExerciese,
      title: Texts.phase_one_exercies_three_title,
      body: Texts.phase_one_exercies_three_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneFourthExerciese,
      title: Texts.phase_one_exercies_four_title,
      body: Texts.phase_one_exercies_five_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneFivthExerciese,
      title: Texts.phase_one_exercies_five_title,
      body: Texts.phase_one_exercies_five_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneSixthExerciese,
      title: Texts.phase_one_exercies_six_title,
      body: Texts.phase_one_exercies_six_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneSeventhExerciese,
      title: Texts.phase_one_exercies_seven_title,
      body: Texts.phase_one_exercies_seven_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneEightthExerciese,
      title: Texts.phase_one_exercies_eight_title,
      body: Texts.phase_one_exercies_eight_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneNinthExerciese,
      title: Texts.phase_one_exercies_nine_title,
      body: Texts.phase_one_exercies_nine_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneTenthExerciese,
      title: Texts.phase_one_exercies_ten_title,
      body: Texts.phase_one_exercies_ten_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneEleventhExerciese,
      title: Texts.phase_one_exercies_eleven_title,
      body: Texts.phase_one_exercies_eleven_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneTwelvethExerciese,
      title: Texts.phase_one_exercies_twelve_title,
      body: Texts.phase_one_exercies_twelve_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseOneTherteenthExerciese,
      title: Texts.phase_one_exercies_thirteen_title,
      body: Texts.phase_one_exercies_thirteen_Body,
      color: AppColor.primary,
    )
  ];
  List<BoardingModel> phaseTwo = [
    BoardingModel(
      image: Assets.phaseTwoRefusedRefusedOne,
      title: Texts.exercies_refused_title,
      body: Texts.exercies_refused_Body,
      color: AppColor.error,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseOne,
      title: Texts.phase_two_exercies_one_title,
      body: Texts.phase_two_exercies_one_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseTwo,
      title: Texts.phase_two_exercies_two_title,
      body: Texts.phase_two_exercies_two_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseThree,
      title: Texts.phase_two_exercies_three_title,
      body: Texts.phase_two_exercies_three_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseFour,
      title: Texts.phase_two_exercies_four_title,
      body: Texts.phase_two_exercies_five_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseFive,
      title: Texts.phase_two_exercies_five_title,
      body: Texts.phase_two_exercies_five_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseSix,
      title: Texts.phase_two_exercies_six_title,
      body: Texts.phase_two_exercies_six_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseSeven,
      title: Texts.phase_two_exercies_seven_title,
      body: Texts.phase_two_exercies_seven_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseEight,
      title: Texts.phase_two_exercies_eight_title,
      body: Texts.phase_two_exercies_eight_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseNine,
      title: Texts.phase_two_exercies_nine_title,
      body: Texts.phase_two_exercies_nine_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseTen,
      title: Texts.phase_two_exercies_ten_title,
      body: Texts.phase_two_exercies_ten_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseEleven,
      title: Texts.phase_two_exercies_eleven_title,
      body: Texts.phase_two_exercies_eleven_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseTwelve,
      title: Texts.phase_two_exercies_twelve_title,
      body: Texts.phase_two_exercies_twelve_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseThirteen,
      title: Texts.phase_two_exercies_thirteen_title,
      body: Texts.phase_two_exercies_thirteen_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseFifteen,
      title: Texts.phase_two_exercies_fourteen_title,
      body: Texts.phase_two_exercies_fourteen_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseFifteen,
      title: Texts.phase_two_exercies_fifteen_title,
      body: Texts.phase_two_exercies_fifteen_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseSixteen,
      title: Texts.phase_two_exercies_sixteen_title,
      body: Texts.phase_two_exercies_sixteen_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseSeventeen,
      title: Texts.phase_two_exercies_seventeen_title,
      body: Texts.phase_two_exercies_seventeen_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseEighteen,
      title: Texts.phase_two_exercies_eighteen_title,
      body: Texts.phase_two_exercies_eighteen_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseNinteen,
      title: Texts.phase_two_exercies_ninteen_title,
      body: Texts.phase_two_exercies_ninteen_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseTwinty,
      title: Texts.phase_two_exercies_twinty_title,
      body: Texts.phase_two_exercies_twinty_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseTwintyOne,
      title: Texts.phase_two_exercies_twinty_one_title,
      body: Texts.phase_two_exercies_twinty_one_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseTwintyTwo,
      title: Texts.phase_two_exercies_twinty_two_title,
      body: Texts.phase_two_exercies_twinty_two_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseTwintyThree,
      title: Texts.phase_two_exercies_twinty_three_title,
      body: Texts.phase_two_exercies_twinty_three_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseTwoExerciseTwintyFour,
      title: Texts.phase_two_exercies_twinty_four_title,
      body: Texts.phase_two_exercies_twinty_four_Body,
      color: AppColor.primary,
    ),
  ];
  List<BoardingModel> phaseThree = [
    BoardingModel(
      image: Assets.phaseThreeExercise1,
      title: Texts.phase_three_exercies_one_title,
      body: Texts.phase_three_exercies_one_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseThreeExercise2,
      title: Texts.phase_three_exercies_two_title,
      body: Texts.phase_three_exercies_two_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseThreeExercise3,
      title: Texts.phase_three_exercies_three_title,
      body: Texts.phase_three_exercies_three_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseThreeExercise4,
      title: Texts.phase_three_exercies_four_title,
      body: Texts.phase_three_exercies_five_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseThreeExercise5,
      title: Texts.phase_three_exercies_five_title,
      body: Texts.phase_three_exercies_five_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseThreeExercise6,
      title: Texts.phase_three_exercies_six_title,
      body: Texts.phase_three_exercies_six_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseThreeExercise7,
      title: Texts.phase_three_exercies_seven_title,
      body: Texts.phase_three_exercies_seven_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseThreeExercise8,
      title: Texts.phase_three_exercies_eight_title,
      body: Texts.phase_three_exercies_eight_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseThreeExercise9,
      title: Texts.phase_three_exercies_nine_title,
      body: Texts.phase_three_exercies_nine_Body,
      color: AppColor.primary,
    ),
    BoardingModel(
      image: Assets.phaseThreeExercise10,
      title: Texts.phase_three_exercies_ten_title,
      body: Texts.phase_three_exercies_ten_Body,
      color: AppColor.primary,
    ),
  ];

  channelConnect() {
    //function to connect
    try {
      emit(ConnectToServerLoadingState());
      channel = IOWebSocketChannel.connect(
        // "ws://192.168.137.16:81",
        "ws://192.168.43.16:81",
      ); //channel IP : Port
      emit(AppChangeState());
      channel!.stream.listen(
        (message) {
          if (message == "connected") {
            connected = true; //message is "connected" from NodeMCU
            emit(ConnectToServerSuccessState());
          } else if (message == "poweron:success") {
            ledStatus = true;
            emit(AppChangeState());
          } else if (message == "poweroff:success") {
            ledStatus = false;
            emit(AppChangeState());
          } else {
            socketMessage = message;
            String input = socketMessage;

            // Remove "ypr:" from the string
            String valuesString = input.replaceFirst("ypr:", "");

            // Split the remaining string using comma as a separator
            List<String> valueList = valuesString.split(',');

            // Convert the substrings to double values
            double y = double.parse(valueList[0].trim());
            double p = double.parse(valueList[1].trim());
            double r = double.parse(valueList[2].trim());
            yawMessage = y.toString();
            pitchMessage = p.toString();
            rollMessage = r.toString();
            emit(AppChangeState());
          }
        },
      );

      onDone:
      () {
        //if WebSocket is disconnected
        // print("Web socket is closed");
        connected = false;
        emit(DisconnectToServerSuccessState());
      };
      onError:
      (error) {
        // print(error.toString());
        emit(ConnectToServerErrorState());
      };
    } catch (_) {
      // print("error on connecting to websocket.");
      emit(ConnectToServerErrorState());
    }
  }

  void channelDisconnect() {
    try {
      if (channel != null) {
        channel!.sink.close();
        connected = false;
        emit(DisconnectToServerSuccessState());
      } else {
        // print("WebSocket channel is already null");
      }
    } catch (_) {
      // print("Error on disconnecting from WebSocket.");
      emit(DisconnectToServerErrorState());
    }
  }

  Future<void> sendCmd(String cmd) async {
    emit(SendToServerLoadingState());
    if (connected == true) {
      if (ledStatus == false && cmd != "poweron" && cmd != "poweroff") {
        // print("Send the valid command");
        emit(SendToServerSuccessState());
      } else {
        channel!.sink.add(cmd); //sending Command to NodeMCU
        emit(SendToServerSuccessState());
      }
    } else {
      emit(SendToServerErrorState());
      channelConnect();
      // print("Websocket is not connected.");
    }
  }

  changeStatus() {
    emit(AppChangeState());
  }

  @override
  Future<void> close() {
    channelDisconnect();
    return super.close();
  }
}
