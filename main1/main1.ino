  
#include <Servo.h>

// Arreglo para servomotores
Servo servoMotor[6];

// Arreglo con los angulos a sobreescribir
int anguloServo[6];

/*
 * La posicion en el arreglo de servomotores corresponde al pin asignado + 1
 * Servo 1 -> [0]
 * Servo 2 -> [1]
 * Servo 3 -> [2]
 * Servo 4 -> [3]
 * Servo 5 -> [4]
 * Servo 6 -> [5]
 */

void setup(){
  // Posiciones iniciales
  anguloServo[0] = 90;
  anguloServo[1] = 45;
  anguloServo[2] = 90;
  anguloServo[3] = 160;
  anguloServo[4] = 90;
  anguloServo[5] = 90;

  servoMotor[0].attach(3);
  servoMotor[1].attach(5);
  servoMotor[2].attach(6);
  servoMotor[3].attach(9);
  servoMotor[4].attach(10);
  servoMotor[5].attach(11);
  
  // Asignando el pin correspondiente a cada servo, y luego moviendolo al angulo inicial
  for(int i = 0; i < 6; i++){
    servoMotor[i].write(anguloServo[i]);
  }
  Serial.begin(9600);
}

void loop(){
  byte datos;
  if (Serial.available()) 
  {
   datos = Serial.read();
    switch(datos){
      case 'z':{          //Pinza de abre
        anguloServo[0]++;
        anguloServo[0] = constrain(anguloServo[0],0,180); 
        servoMotor[0].write(anguloServo[0]);  
        break;
      }
      case 'c':{            //Pinza se cierra
        anguloServo[0]--;
        anguloServo[0] = constrain(anguloServo[0],0,180); 
        servoMotor[0].write(anguloServo[0]); 
        break;
      }
      case '8': {             //Muñeca vertical sube
        anguloServo[1]++;
        anguloServo[1] = constrain(anguloServo[1],0,180); 
        servoMotor[1].write(anguloServo[1]);  
        break;
      }
      case '5':{              //Muñeca vertical baja
        anguloServo[1]--;
        anguloServo[1] = constrain(anguloServo[1],0,180); 
        servoMotor[1].write(anguloServo[1]); 
        break;
      }
      case '6':{            //Muñeca gira a la derecha
        anguloServo[2]++;
        anguloServo[2] = constrain(anguloServo[2],0,180); 
        servoMotor[2].write(anguloServo[2]); 
        break;
      }w
      case '4':{              //Muñeca gira a la izquierda
        anguloServo[2]--;
        anguloServo[2] = constrain(anguloServo[2],0,180); 
        servoMotor[2].write(anguloServo[2]); 
        break;
      } 
      case 'q':{              //Codo sube
        anguloServo[3]++;
        anguloServo[3] = constrain(anguloServo[3],0,180); 
        servoMotor[3].write(anguloServo[3]); 
        break;
      }
      case 'e':{              //Codo baja
        anguloServo[3]--;
        anguloServo[3] = constrain(anguloServo[3],0,180); 
        servoMotor[3].write(anguloServo[3]); 
        break;
      }
      case 'w':{              //Hombro sube 
        anguloServo[4]++;
        anguloServo[4] = constrain(anguloServo[4],0,180); 
        servoMotor[4].write(anguloServo[4]); 
        break;
      }
      case 's':{              //Hombro baja
        anguloServo[4]--;
        anguloServo[4] = constrain(anguloServo[4],0,180); 
        servoMotor[4].write(anguloServo[4]); 
        break;
      }
      case 'd':{            //Base gira a la derecha
        anguloServo[5]++;
        anguloServo[5] = constrain(anguloServo[5],0,180); 
        servoMotor[5].write(anguloServo[5]); 
        break;
      }
      case 'a':{            //Base gira a la izquierda
        anguloServo[5]--;
        anguloServo[5] = constrain(anguloServo[5],0,180); 
        servoMotor[5].write(anguloServo[5]); 
        break;
      }
    }
   }
}
