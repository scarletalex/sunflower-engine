import requests

while(True) :
   valor = int(input("Informe um valor: "))
   r = requests.post("https://stellar-engine.herokuapp.com/upload", json={"TENSAO":valor})
   print(r.status_code)
