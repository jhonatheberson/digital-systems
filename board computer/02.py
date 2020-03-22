import threading
from time import sleep
lock = threading.Lock()


# funcao que espera 1 segundo

def wait():
    global lock
    while True:
        sleep(1)
        lock.release()

def LerVelocidade():
    global lock
    while True:
        lock.acquire()
        print('Leitura da Velocidade')
        print('cheguei')




# ----------------criando a thread
lock.acquire()
t = threading.Thread(target=wait, name='Wait')
t1 = threading.Thread(target=LerVelocidade, name='Velocidade')
t.start()
t1.start()

