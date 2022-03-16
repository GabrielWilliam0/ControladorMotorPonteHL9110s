/*
* Programa: Controle de rotação dos motores | mini driver ponte h L9110
* Autor: Gabriel William
* E-mail: gabrielwilliam060709022gmail.com
*/

class ControllerMotor {
  // driver variável responsável por armazenar o valor máximo da velocidade do motor.
  int driver = 255, pin1, pin2;
  // pin1 e pin2 são variáveis que armazenaram o valor dos pinos no arduino.

  public:

    void Pindef(int in1, int in2) {
      // método responsável por declarar os pinos para o controle do motor
      pin1 = in1;
      pin2 = in2;
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
    }

    void Speed(int in1){
      // armazena velocidade do motor
      driver = in1;
    }

    void Forward(){
      // função responsável por fazer o motor girar em sentido horário de acordo com o sinal PWM passado no método Speed.
      analogWrite(pin1, driver);
      // analogWrite envia um sinal PWM para pin1, e faz o motor girar no sentido horário.
      digitalWrite(pin2, LOW);
      // desliga o sentido anti-horário do motor.
    }

    void Backward(){
      digitalWrite(pin1, LOW);
      // desliga o sentido horário do motor.
      analogWrite(pin2, driver);
      // envia um sinal PWM para pin2, e faz o motor girar no sentido anti-horário.
    }

    void Stop(){
      // desliga a rotação anti-horária e horário, deixando o motor parado.
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
    }
};

// Criando o Objeto Motor1
ControllerMotor Motor1;


void setup(){
  // Chama o método Pindef do Objeto Motor1, e define quais pinos seram usados para controlar o motor.
  Motor1.Pindef(9, 10);
}

void loop(){
  // Chama o método Forward fazendo o motor girar em sentido horário.
  Motor1.Forward();

  // Chama o método Backward fazendo o motor girar em sentido anti-horário.
  Motor1.Backward();

  // Chama o método Stop fazendo o motor parar.
  Motor1.Stop();
}
