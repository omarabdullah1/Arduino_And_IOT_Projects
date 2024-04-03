import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import '../../../business_logic/global_cubit/global_cubit.dart';
import '../../../data/local/cache_helper.dart';
import '../../../generated/assets.dart';

import '../../generated_data/Texts.dart';
import '../../generated_data/screens.dart';
import '../../styles/colors.dart';

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  @override
  void initState() {
    GlobalCubit.get(context).loginModel ??
        GlobalCubit.get(context).userLogin(
          email: CacheHelper.getDataFromSharedPreference(key: 'email'),
          password: CacheHelper.getDataFromSharedPreference(key: 'password'),
          context: context,
        );
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    final GlobalCubit globalCubit = context.read<GlobalCubit>();
    return BlocConsumer<GlobalCubit, GlobalState>(
      listener: (context, state) {},
      builder: (context, state) {
        return globalCubit.loginModel != null
            ? Scaffold(
                backgroundColor: AppColor.babyBlue,
                body: SafeArea(
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.start,
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Padding(
                        padding: const EdgeInsets.all(8.0),
                        child: Container(
                          height: 100.0,
                          decoration: BoxDecoration(
                            border: Border.all(
                              color: AppColor.roseMadder,
                              width: 2.0,
                            ),
                            borderRadius: BorderRadius.circular(20),
                            color: AppColor.indigoDye500,
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
                            child: Row(
                              crossAxisAlignment: CrossAxisAlignment.center,
                              // textBaseline: TextBaseline.ideographic,
                              children: [
                                CircleAvatar(
                                  child: Image.asset(
                                    Assets.imagesPerson,
                                    fit: BoxFit.cover,
                                    height: 85.0,
                                    width: 80.0,
                                  ),
                                ),
                                Padding(
                                  padding: const EdgeInsets.symmetric(
                                    horizontal: 15.0,
                                  ),
                                  child: SizedBox(
                                    height: 80.0,
                                    child: Column(
                                      crossAxisAlignment:
                                          CrossAxisAlignment.start,
                                      children: [
                                        Text(
                                          globalCubit.loginModel!.name
                                              .toString(),
                                          style: TextStyles
                                              .studentHomeProfileNameTextStyle,
                                        ),
                                        Text(
                                          globalCubit.loginModel!.email
                                              .toString(),
                                          style: TextStyles
                                              .studentHomeProfileTypeTextStyle,
                                        ),
                                        Text(
                                          globalCubit.loginModel!.phone
                                              .toString(),
                                          style: TextStyles
                                              .studentHomeProfileTypeTextStyle,
                                        )
                                      ],
                                    ),
                                  ),
                                )
                              ],
                            ),
                          ),
                        ),
                      ),
                      const SizedBox(
                        height: 20.0,
                      ),
                      Expanded(
                        child: Container(
                          decoration: const BoxDecoration(
                            color: AppColor.white,
                            borderRadius: BorderRadius.only(
                              topLeft: Radius.circular(30.0),
                              topRight: Radius.circular(30.0),
                            ),
                          ),
                          child: Padding(
                            padding: const EdgeInsets.all(15.0),
                            child: Column(
                              children: [
                                InkWell(
                                  onTap: () {
                                    Navigator.pushNamed(
                                      context,
                                      Screens.phaseOneScreen,
                                    );
                                  },
                                  child: Padding(
                                    padding: const EdgeInsets.only(
                                      top: 24.0,
                                      bottom: 9.0,
                                    ),
                                    child: Row(
                                      children: [
                                        CircleAvatar(
                                          backgroundColor: AppColor.roseMadder
                                              .withOpacity(0.1),
                                          child: const Icon(
                                            Icons.one_k_outlined,
                                            color: AppColor.roseMadder,
                                          ),
                                        ),
                                        Padding(
                                          padding: const EdgeInsets.symmetric(
                                              horizontal: 15.0),
                                          child: Column(
                                            crossAxisAlignment:
                                            CrossAxisAlignment.start,
                                            children: [
                                              Text(
                                                Texts.phaseOneButtonText,
                                                style: TextStyles
                                                    .studentHomeProfilePersonalAccountTextStyle,
                                              ),
                                              Text(
                                                Texts.phaseOneButtonBodyText,
                                                style: TextStyles
                                                    .studentHomeProfilePersonalAccountEditTextStyle,
                                              ),
                                            ],
                                          ),
                                        ),
                                        const Spacer(),
                                        IconButton(
                                          onPressed: () {
                                            Navigator.pushNamed(
                                              context,
                                              Screens.phaseOneScreen,
                                            );
                                          },
                                          icon: Icon(
                                            Icons.arrow_forward_ios,
                                            color: AppColor.grey.withOpacity(0.6),
                                          ),
                                        ),
                                      ],
                                    ),
                                  ),
                                ),
                                InkWell(
                                  onTap: () {
                                    Navigator.pushNamed(
                                      context,
                                      Screens.phaseTwoScreen,
                                    );
                                  },
                                  child: Padding(
                                    padding: const EdgeInsets.only(
                                      top: 24.0,
                                      bottom: 9.0,
                                    ),
                                    child: Row(
                                      children: [
                                        CircleAvatar(
                                          backgroundColor: AppColor.roseMadder
                                              .withOpacity(0.1),
                                          child: const Icon(
                                            Icons.two_k_outlined,
                                            color: AppColor.roseMadder,
                                          ),
                                        ),
                                        Padding(
                                          padding: const EdgeInsets.symmetric(
                                              horizontal: 15.0),
                                          child: Column(
                                            crossAxisAlignment:
                                            CrossAxisAlignment.start,
                                            children: [
                                              Text(
                                                Texts.phaseTwoButtonText,
                                                style: TextStyles
                                                    .studentHomeProfilePersonalAccountTextStyle,
                                              ),
                                              Text(
                                                Texts.phaseTwoButtonBodyText,
                                                style: TextStyles
                                                    .studentHomeProfilePersonalAccountEditTextStyle,
                                              ),
                                            ],
                                          ),
                                        ),
                                        const Spacer(),
                                        IconButton(
                                          onPressed: () {
                                            Navigator.pushNamed(
                                              context,
                                              Screens.phaseTwoScreen,
                                            );
                                          },
                                          icon: Icon(
                                            Icons.arrow_forward_ios,
                                            color: AppColor.grey.withOpacity(0.6),
                                          ),
                                        ),
                                      ],
                                    ),
                                  ),
                                ),
                                InkWell(
                                  onTap: () {
                                    Navigator.pushNamed(
                                      context,
                                      Screens.phaseThreeScreen,
                                    );
                                  },
                                  child: Padding(
                                    padding: const EdgeInsets.only(
                                      top: 24.0,
                                      bottom: 9.0,
                                    ),
                                    child: Row(
                                      children: [
                                        CircleAvatar(
                                          backgroundColor: AppColor.roseMadder
                                              .withOpacity(0.1),
                                          child: const Icon(
                                            Icons.three_k_outlined,
                                            color: AppColor.roseMadder,
                                          ),
                                        ),
                                        Padding(
                                          padding: const EdgeInsets.symmetric(
                                              horizontal: 15.0),
                                          child: Column(
                                            crossAxisAlignment:
                                            CrossAxisAlignment.start,
                                            children: [
                                              Text(
                                                Texts.phaseThreeButtonText,
                                                style: TextStyles
                                                    .studentHomeProfilePersonalAccountTextStyle,
                                              ),
                                              Text(
                                                Texts.phaseThreeButtonBodyText,
                                                style: TextStyles
                                                    .studentHomeProfilePersonalAccountEditTextStyle,
                                              ),
                                            ],
                                          ),
                                        ),
                                        const Spacer(),
                                        IconButton(
                                          onPressed: () {
                                            Navigator.pushNamed(
                                              context,
                                              Screens.phaseThreeScreen,
                                            );
                                          },
                                          icon: Icon(
                                            Icons.arrow_forward_ios,
                                            color: AppColor.grey.withOpacity(0.6),
                                          ),
                                        ),
                                      ],
                                    ),
                                  ),
                                ),

                                InkWell(
                                  onTap: () {
                                    globalCubit.logout(context);
                                  },
                                  child: Padding(
                                    padding: const EdgeInsets.only(
                                      top: 9.0,
                                      bottom: 9.0,
                                    ),
                                    child: Row(
                                      children: [
                                        CircleAvatar(
                                          backgroundColor: AppColor.roseMadder
                                              .withOpacity(0.1),
                                          child: const Icon(
                                            Icons.logout_outlined,
                                            color: AppColor.roseMadder,
                                          ),
                                        ),
                                        Padding(
                                          padding: const EdgeInsets.symmetric(
                                              horizontal: 15.0),
                                          child: Column(
                                            crossAxisAlignment:
                                            CrossAxisAlignment.start,
                                            children: [
                                              Text(
                                                Texts.studentHomeLogoutText,
                                                style: TextStyles
                                                    .studentHomeProfilePersonalAccountTextStyle,
                                              ),
                                              Text(
                                                Texts.studentHomeProfileLogOutEditTextText,
                                                style: TextStyles
                                                    .studentHomeProfilePersonalAccountEditTextStyle,
                                              ),
                                            ],
                                          ),
                                        ),
                                        const Spacer(),
                                        IconButton(
                                          onPressed: () {
                                            globalCubit.logout(context);
                                          },
                                          icon: Icon(
                                            Icons.arrow_forward_ios,
                                            color: AppColor.grey.withOpacity(0.6),
                                          ),
                                        ),
                                      ],
                                    ),
                                  ),
                                ),
                              ],
                            ),
                          ),
                        ),
                      )
                    ],
                  ),
                ),
              )
            : const Scaffold(
                body: Center(child: CircularProgressIndicator()),
              );
      },
    );
  }
}
