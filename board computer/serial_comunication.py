import serial

port = "/dev/ttyACM0"
speed = 9600
conected = serial.Serial(port, speed)
print(b'helllo')
opcao = 0

while opcao != "100":
    print("==========================================================")
    print("--------------------COMPUADOR DE BORDO--------------------")
    print("==========================================================")
    opcao = input("Digite 0 para desligar farol\n Digite 1 para ligar farol\n"
                  "Digite 2 para ligar pisca esquerda\n Digite 3 para ligar pisca direita\n"
                  "Digite 100 para parar\n: )
    if opcao == "1":
        conected.write(b'1')
    elif opcao == "0":
        conected.write(b'0')
    elif opcao == "2":
        conected.write(b'2')
    elif opcao == "3":
        conected.write(b'3')
conected.close()
