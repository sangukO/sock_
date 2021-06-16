from socket import *
from threading import *

class MultiChatServer:
    clients = []
    final_received_message = ""

    def __init__(self):
        self.s_sock = socket(AF_INET, SOCK_STREAM)
        self.ip = ''
        self.port = 2500
        self.s_sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
        self.s_sock.bind((self.ip, self.port))
        print("Waiting for clients...")
        self.s_sock.listen(100)
        self.accept_client()
    
    def accept_client(self):
        while True:
            client = c_socket, (ip, port) = self.s_sock.accept()
            if client not in self.clients:
                self.clients.append(client)
            print (ip, ':', str(port), '가 연결되었습니다.')
            t = Thread(target=self.receive_messages, args=(c_socket,))
            t.start()

    def receive_messages(self, c_socket):
        while True:
            try:
                incoming_message = c_socket.recv(1024)
                if not incoming_message:
                    break
            except:
                continue
            else:
                self.final_received_message = incoming_message.decode('utf-8')
                print(self.final_received_message)
                self.send_all_clients(c_socket)
        c_socket.close()
    
    def send_all_clients(self, senders_socket):
        for client in self.clients:
            socket, (ip, port) = client
            if socket is not senders_socket:
                try:
                    socket.sendall(self.final_received_message.encode('utf-8'))
                except:
                    self.clients.remove(client)
                    print("{}, {} 연결이 종료되었습니다.".format(ip, port))

if __name__ == "__main__":
    MultiChatServer()
