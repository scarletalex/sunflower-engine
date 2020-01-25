import requests

while(True) :
   valor = int(input("Informe um valor: "))
   r = requests.post("https://stellar-engine.herokuapp.com/upload", json={"LDR":valor})
   print(r.status_code)
