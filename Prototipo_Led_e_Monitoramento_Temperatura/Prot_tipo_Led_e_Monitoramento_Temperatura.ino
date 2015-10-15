/*Protótipo - Led e Monitoramento de Temperatura
Automação Inclusiva - Um Novo Olhar na Automação para Deficientes Físicos
www.automacaoinclusiva.com.br */

//DECLARACAO DAS VARIAVEIS GLOBAIS
int led = 9; //porta da leitura do led
int temp; // variavel do sensor de temperatura
boolean status = LOW; //variavel do estado do led

//BLOCO DE CODIGO QUE SERA EXECUTADO UMA UNICA VEZ
void setup() {
    Serial.begin(9600); //porta serial de comunicacao para envio de informacoes
    pinMode(led, OUTPUT); //definicao da porta do led como saida
}

//BLOCO DE CODIGO QUE SERA EXECUTADO VARIAS VEZES
void loop() {
    temp = analogRead(A0); //lendo o dados do sensor LM35
    temp = (5.0 * temp * 100) / 1023.0; //formula p/ converter a temperatura lida em graus celsius
    Serial.print("Temperatura: ");
    Serial.println(temp); //escrevendo a temperatura na saida serial
    delay(1000); //esperando um segundo

    if (Serial.available() > 0) //testando o dados recebidos pela porta serial
    {
        byte dado = Serial.read(); //variavel que armazena o dado lido na entrada serial
        if (dado == 65) //caso receba a letra “A” (codigo ASCII "65")
        {
            status = !status; //inverte o status atual do led
        }
        digitalWrite(led, status); //apaga ou desliga o led conforme o status
    }
}
