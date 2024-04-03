// import 'package:flutter/material.dart';
// import 'package:flutter_bloc/flutter_bloc.dart';
// import '../../../business_logic/app_localization.dart';
// import '../../../business_logic/global_cubit/global_cubit.dart';
// import '../../../data/local/cache_helper.dart';
// import '../styles/colors.dart';
//
// class GetDataScreen extends StatefulWidget {
//   const GetDataScreen({super.key});
//
//   @override
//   State<GetDataScreen> createState() => _GetDataScreenState();
// }
//
// class _GetDataScreenState extends State<GetDataScreen> {
//   @override
//   void initState() {
//     GlobalCubit.get(context)
//         .channelConnect(); //connect to WebSocket wth NodeMCU
//     super.initState();
//   }
//
//   @override
//   Widget build(BuildContext context) {
//     final GlobalCubit globalCubit = context.read<GlobalCubit>();
//     return BlocConsumer<GlobalCubit, GlobalState>(
//       listener: (context, state) {},
//       builder: (context, state) {
//         return globalCubit.channel != null
//             ? Scaffold(
//           appBar: AppBar(
//             title: const Text('Data Screen'),
//             centerTitle: true,
//           ),
//           body: SafeArea(
//             child: Padding(
//               padding: const EdgeInsets.all(12.0),
//               child: Column(
//                 mainAxisAlignment: MainAxisAlignment.start,
//                 crossAxisAlignment: CrossAxisAlignment.start,
//                 children: [
//                   Container(
//                     alignment: Alignment.topCenter,
//                     //inner widget alignment to center
//                     padding: const EdgeInsets.all(20),
//                     child: Column(
//                       children: [
//                         Container(
//                             child: globalCubit.connected
//                                 ? const Text("WEBSOCKET: CONNECTED")
//                                 : const Text("DISCONNECTED")),
//                         Container(
//                             child: globalCubit.ledStatus
//                                 ? const Text("LED IS: ON")
//                                 : const Text("LED IS: OFF")),
//                         MaterialButton(
//                           onPressed: () {
//                             globalCubit.channelConnect();
//                           },
//                           color: AppColor.primary,
//                           child: globalCubit.connected
//                               ? const Text("WEBSOCKET: CONNECTED",style: TextStyle(color: AppColor.white),)
//                               : const Text("DISCONNECTED",style: TextStyle(color: AppColor.white),),
//                         ),
//                         Text('MESSAGE:  ${globalCubit.socketMessage}'),
//                         Text('pitch:  ${globalCubit.pitchMessage}'),
//                         Text('roll:  ${globalCubit.rollMessage}'),
//                         Text('yaw:  ${globalCubit.yawMessage}'),
//                         Padding(
//                           padding: const EdgeInsets.all(8.0),
//                           child: Text(double.parse(globalCubit.rollMessage)>-11&&double.parse(globalCubit.rollMessage)<11?'in scpular':'out scapular'),
//                         ),
//                         Container(
//                           margin: const EdgeInsets.only(top: 30),
//                           child: MaterialButton(
//                             //button to start scanning
//                             color: Colors.redAccent,
//                             colorBrightness: Brightness.dark,
//                             onPressed: () {
//                               //on button press
//                               if (globalCubit.ledStatus) {
//                                 //if ledstatus is true, then turn off the led
//                                 //if led is on, turn off
//                                 globalCubit.sendCmd("poweroff");
//                                 globalCubit.ledStatus = false;
//                               } else {
//                                 //if ledstatus is false, then turn on the led
//                                 //if led is off, turn on
//                                 globalCubit.sendCmd("poweron");
//                                 globalCubit.ledStatus = true;
//                               }
//                               globalCubit.changeStatus();
//                             },
//                             child: globalCubit.ledStatus
//                                 ? const Text("TURN LED OFF")
//                                 : const Text("TURN LED ON"),
//                           ),
//                         ),
//                       ],
//                     ),
//                   ),
//                 ],
//               ),
//             ),
//           ),
//         )
//             : const Scaffold(
//           body: Center(child: CircularProgressIndicator()),
//         );
//       },
//     );
//   }
// }
