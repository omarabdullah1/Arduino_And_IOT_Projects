#define DHTTYPE DHT11   // DHT 11

#define dht_dpin 5
#define S0 0                             /* Assign Multiplexer pin S0 connect to pin D0 of NodeMCU */
#define S1 2                             /* Assign Multiplexer pin S1 connect to pin D1 of NodeMCU */
#define S2 14                             /* Assign Multiplexer pin S2 connect to pin D2 of NodeMCU */
#define S3 12                             /* Assign Multiplexer pin S3 connect to pin D3 of NodeMCU */
#define SIG A0                            /* Assign SIG pin as Analog output for all 16 channels of Multiplexer to pin A0 of NodeMCU */

int decimal = 2;                        /* Decimal places of the sensor value outputs */
int sensor0;                            /* Assign the name "sensor0" as analog output value from Channel C0 */
int sensor1;                            /* Assign the name "sensor1" as analog output value from Channel C1 */
int sensor2;                            /* Assign the name "sensor2" as analog output value from Channel C2 */
int sensor3;                            /* Assign the name "sensor3" as analog output value from Channel C3 */
int sensor4;                            /* Assign the name "sensor4" as analog output value from Channel C4 */
int voltageSensor;
int moistureSensor;

DHT dht(dht_dpin, DHTTYPE);

float vOUT = 0.0;
float vIN = 0.0;
float R1 = 30000.0;
float R2 = 7900.0;
int value = 0;
char auth[] = "I0qv69-MdqfSTj4slsFMOtkk52cp3A4_";

char ssid[] = "HTI samy cs2017";
char pass[] = "01271901251samy7799";
void Init();
void getSensorData();
