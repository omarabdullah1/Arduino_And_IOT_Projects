
File ourUser;
File ourVote;
bool backsensed = false;
bool resetsensed = false;

//Sense touch trough these pins
#define YP A3  // must be an analog pin
#define XM A2  // must be an analog pin
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

#define TS_MINX 100
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940
//Create the touchscreen object
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);  //(data,data,data,data,sensitivity);

//Some of the tft pins
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
// Optional, used to reset the display
#define LCD_RESET A4

#define SD_CS 10 // Card select for shield use

#define REDBAR_MINX 80
#define GREENBAR_MINX 130
#define BLUEBAR_MINX 180
#define BAR_MINY 30
#define BAR_HEIGHT 250
#define BAR_WIDTH 30

//Create the tft object
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

// Define some TFT readable colour codes to human readable names
#define BLACK   0x0000
int BLUE = tft.color565(50, 50, 255);
#define DARKBLUE 0x0010
#define VIOLET 0x8888
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY   tft.color565(64, 64, 64);
#define GOLD 0xFEA0
#define BROWN 0xA145
#define SILVER 0xC618
#define LIME 0x07E0

//Sd Card Pins


//Minimum and maximum pressure to sense the touch
#define MINPRESSURE 5
#define MAXPRESSURE 1000

#define DRAW_LOOP_INTERVAL 50  //The interval used instead of delay(); 

void Init();
void Splash();
void waitingPage();
void votingPage();
void byePage(int);
void replaceVoteData(int data);
String getUser();
int getVote();
//int getFingerprintIDez();

int currentpage;
String Name = "";

int myId = 0;//getFingerprintIDez()
char folderUser[] = {"/Userss/"};
char folderVote[] = {"/Votess/"};
//char folderVotee[] = {"/Votess/3.txt"};
