import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/painting.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:shoulder_exercises/business_logic/phase_cubit/phase_cubit.dart';
import 'package:smooth_page_indicator/smooth_page_indicator.dart';
import '../../business_logic/phase_cubit/phase_state.dart';
import '../generated_data/Texts.dart';
import '../styles/colors.dart';

class PhaseOneScreen extends StatelessWidget {
  const PhaseOneScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return BlocProvider(
      create: (context) => PhaseCubit()..channelConnect(),
      child: BlocConsumer<PhaseCubit, PhaseState>(
        listener: (context, state) {},
        builder: (context, state) {
          final PhaseCubit phaseCubit = context.read<PhaseCubit>();
          return Scaffold(
            appBar: AppBar(
              title: Text(
                'Phase One',
                style: TextStyles.studentHomeHomepageStyle,
              ),
              centerTitle: true,
              actions: [
                IconButton(
                  onPressed: () {
                    phaseCubit.connected
                        ? phaseCubit.channelDisconnect()
                        : phaseCubit.channelConnect();
                  },
                  color: AppColor.primary,
                  icon: phaseCubit.connected
                      ? const Icon(Icons.private_connectivity_rounded)
                      : const Icon(Icons.private_connectivity_outlined),
                ),
              ],
            ),
            body: SafeArea(
              child: Padding(
                padding: const EdgeInsets.all(12.0),
                child: SingleChildScrollView(
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.start,
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Container(
                        alignment: Alignment.topCenter,
                        //inner widget alignment to center
                        padding: const EdgeInsets.all(8),
                        child: Column(
                          children: [
                            const Text(
                              'Phase 1 (0-6) weeks in scapular plane',
                            ),
                            const SizedBox(
                              height: 5.0,
                            ),
                            Padding(
                              padding: const EdgeInsets.all(8.0),
                              child: Container(
                                  child: phaseCubit.connected
                                      ? const Text("WEBSOCKET: CONNECTED")
                                      : const Text("DISCONNECTED")),
                            ),
                            // Container(
                            //     child: globalCubit.ledStatus
                            //         ? const Text("LED IS: ON")
                            //         : const Text("LED IS: OFF")),

                            SizedBox(
                              height: MediaQuery.of(context).size.height * 0.5,
                              width: MediaQuery.of(context).size.width,
                              child: PageView.builder(
                                physics: const BouncingScrollPhysics(),
                                controller: phaseCubit.boardController,
                                onPageChanged: (int index) {
                                  if (index == 0) {
                                    phaseCubit.isFirst = true;
                                    phaseCubit.changeStatus();
                                  } else {
                                    phaseCubit.isFirst = false;
                                    phaseCubit.changeStatus();
                                  }
                                  if (index == 2) {
                                    phaseCubit.isLast = true;
                                    phaseCubit.changeStatus();
                                  } else {
                                    phaseCubit.isLast = false;
                                    phaseCubit.changeStatus();
                                  }
                                },
                                itemBuilder: (context, index) =>
                                    buildBoardingItem(
                                  phaseCubit.phaseOne[index],
                                  context,
                                ),
                                itemCount: phaseCubit.phaseOne.length,
                              ),
                            ),
                            phaseCubit.rollMessage.isNotEmpty
                                ? Padding(
                                    padding: const EdgeInsets.all(8.0),
                                    child: Container(
                                      width: 120,
                                      height: 40.0,
                                      decoration: BoxDecoration(
                                        borderRadius: BorderRadius.circular(15),
                                        color: double.parse(phaseCubit
                                                        .rollMessage) >
                                                    -45 &&
                                                double.parse(phaseCubit
                                                        .rollMessage) <
                                                    0
                                            ? AppColor.green
                                            : AppColor.roseMadder,
                                      ),
                                      child: Center(
                                        child: Text(
                                          double.parse(phaseCubit.rollMessage) >
                                                      -11 &&
                                                  double.parse(phaseCubit
                                                          .rollMessage) <
                                                      11
                                              ? 'in scpular'
                                              : 'out scapular',
                                          style: TextStyles.startNowStyle,
                                        ),
                                      ),
                                    ),
                                  )
                                : const SizedBox(),
                            Padding(
                              padding: const EdgeInsets.all(8.0),
                              child: Container(
                                height: 150.0,
                                width: MediaQuery.of(context).size.width * 0.98,
                                decoration: BoxDecoration(
                                  border: Border.all(
                                    color: AppColor.roseMadder,
                                    width: 2.0,
                                  ),
                                  borderRadius: BorderRadius.circular(20),
                                  color: AppColor.indigoDye300,
                                  boxShadow: <BoxShadow>[
                                    BoxShadow(
                                      color: AppColor.black.withOpacity(0.4),
                                      blurRadius: 35,
                                      offset: const Offset(0, 0),
                                    ),
                                  ],
                                ),
                                child: Padding(
                                  padding: const EdgeInsets.all(15.0),
                                  child: Column(
                                    crossAxisAlignment:
                                        CrossAxisAlignment.center,
                                    // textBaseline: TextBaseline.ideographic,
                                    children: [
                                      Text(
                                        phaseCubit.socketMessage,
                                        style: TextStyles.startNowStyle,
                                      ),
                                      Text(
                                        'pitch:  ${phaseCubit.pitchMessage}',
                                        style: TextStyles.startNowStyle,
                                      ),
                                      Text(
                                        'roll:  ${phaseCubit.rollMessage}',
                                        style: TextStyles.startNowStyle,
                                      ),
                                      Text(
                                        'yaw:  ${phaseCubit.yawMessage}',
                                        style: TextStyles.startNowStyle,
                                      ),
                                    ],
                                  ),
                                ),
                              ),
                            ),
                          ],
                        ),
                      ),
                    ],
                  ),
                ),
              ),
            ),
          );
        },
      ),
    );
  }

  Widget buildBoardingItem(BoardingModel model, BuildContext context) => Column(
        crossAxisAlignment: CrossAxisAlignment.center,
        children: [
          SizedBox(
            height: 250.0,
            child: Image(
              image: AssetImage(model.image),
            ),
          ),
          const SizedBox(
            height: 15.0,
          ),
          Text(
            model.title,
            style:
                TextStyles.studentHomeLevelCoursesTextColoredStyle(model.color),
            textAlign: TextAlign.center,
          ),
          Text(
            model.body,
            style: TextStyles.studentHomeCourseDetailsTextColoredStyle(
              model.color,
            ),
            textAlign: TextAlign.center,
          ),
          const SizedBox(
            height: 15.0,
          ),
          SingleChildScrollView(
            scrollDirection: Axis.horizontal,
            child: Padding(
              padding: const EdgeInsets.all(8.0),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  SmoothPageIndicator(
                    controller: context.read<PhaseCubit>().boardController,
                    effect: ExpandingDotsEffect(
                      dotColor: model.color.withOpacity(0.3),
                      activeDotColor: model.color,
                      dotHeight: 10,
                      expansionFactor: 4,
                      dotWidth: 8,
                      spacing: 5.0,
                    ),
                    count: context.read<PhaseCubit>().phaseOne.length,
                  ),
                  const SizedBox(
                    width: 20.0,
                  ),
                ],
              ),
            ),
          ),
        ],
      );
}

class BoardingModel {
  final String image;
  final String title;
  final String body;
  final Color color;

  BoardingModel({
    required this.title,
    required this.image,
    required this.body,
    required this.color,
  });
}
