void Init() {

  Serial.begin(9600);
//  finger.begin(57600);
//  finger.getTemplateCount();
  tft.reset();
  tft.begin(tft.readID());
  Serial.begin(9600);

  if (!SD.begin(SD_CS)) {
    Serial.println(F("failed!"));
    return;
  }

  tft.fillScreen(BLACK);
  tft.setRotation(1);

  Splash();
  waitingPage();
  Serial.println("CLEARDATA");
Serial.println("LABEL,Acolumn,Bcolumn,...");
//Serial.println("myId,getUser,getVote,...");
Serial.println("RESETTIMER");
  for(int i=1;i<=4;i++){
    myId=i;
    Serial.println(myId);//Serial.println(getUser());Serial.println(getVote());
  }
//  if (getVote() == 0) {
//    votingPage();
//  }
//  else {
//    byePage(getVote());
//  }
}
void Splash() {
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.setCursor(50, 140);
  tft.print("Loading...");

  tft.setTextColor(tft.color565(255, 255, 0));
  tft.setCursor(30, 15);
  tft.print("Smart");

  tft.setCursor(30, 45);
  tft.print("Vote");

  tft.setTextSize(2);

  tft.setCursor(10, 85);
  tft.print("Please Put your finger...");

  for (int i; i < 350; i++)
  {
    tft.fillRect(BAR_MINY - 10, BLUEBAR_MINX, i, 10, RED);
    delay(0.000000000000000000000000000000000000000000000000001);
  }
}
void waitingPage() {
  currentpage = 0;
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setTextColor(tft.color565(255, 255, 0));
  tft.setCursor(10, 30);
  tft.print("Please Put your finger...");
  delay(1000);
}
void votingPage() {
  currentpage = 1;
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(120, 10);
  tft.print("Hello");

  tft.setCursor(15, 40);
  tft.print("Mr.");
  tft.print(getUser());

  tft.setCursor(75, 70);
  tft.print("Please Vote...");


  tft.setTextSize(3);
  tft.setTextColor(tft.color565(255, 255, 0));
  tft.fillRoundRect(10, 100, 130, 130, 8, RED);
  tft.drawRoundRect(10, 100, 130, 130, 8, WHITE); //Oscilloscope
  tft.setCursor(20, 155);
  tft.print("Vote 1");

  tft.fillRoundRect(170, 100, 130, 130, 8, RED);
  tft.drawRoundRect(170, 100, 130, 130, 8, WHITE); //Oscilloscope
  tft.setCursor(180, 155);
  tft.print("Vote 2");
}

void byePage(int vote) {
  currentpage = 2;
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setTextColor(tft.color565(255, 255, 0));
  tft.setCursor(10, 65);
  tft.print("Mr.");
  tft.print(getUser());
  tft.setTextSize(3);
  tft.setCursor(10, 100);
  tft.print("You're voted for ");
  tft.setCursor(115, 135);
  tft.print("No " + String(vote));
  if (getVote() == 0)
    replaceVoteData(vote);
}

String getUser() {
  String user = "";
  char ch;

  ourUser = SD.open(folderUser + String(myId) + ".txt", FILE_READ);
  if (ourUser) {
    while (ourUser.available()) {
      ch = ourUser.read();
      user += ch;
    }
    ourUser.close();
  }
  return user;
}

int getVote() {
  String vote = "";
  char ch;

  ourVote = SD.open(folderVote + String(myId) + ".txt", FILE_READ);
  if (ourVote) {
    while (ourVote.available()) {
      ch = ourVote.read();
      vote += ch;
    }
    ourVote.close();
  }
  return vote.toInt();
}
void replaceVoteData(int data) {
  ourVote = SD.open(folderVote + String(myId) + ".txt", FILE_WRITE);
  SD.remove(folderVote + String(myId) + ".txt");
  SD.open(folderVote + String(myId) + ".txt", FILE_WRITE);
  ourVote.print(data);
  ourVote.close();
  ourUser = SD.open(folderUser + String(myId) + ".txt", FILE_READ);
  ourVote.close();
}

//int getFingerprintIDez() {
//  uint8_t p = finger.getImage();        //Image scanning
//  if (p != FINGERPRINT_OK)  return -1;
//
//  p = finger.image2Tz();               //Converting
//  if (p != FINGERPRINT_OK)  return -1;
//
//  p = finger.fingerFastSearch();     //Looking for matches in the internal memory
//  if (p != FINGERPRINT_OK) {         //if the searching fails it means that the template isn't registered
//    tft.setCursor(10, 100);
//    tft.print("Access denied");
//    delay(2000);
//    waitingPage();
//    return -1;
//  }
//  //If we found a match we proceed in the function
//  return finger.fingerID;
//}
