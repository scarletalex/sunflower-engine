import requests

while(True) :
   valor = int(input("Informe um valor: "))
   r = requests.post("https://sunflower-engine.herokuapp.com/upload", json={"VOLT":valor})
   print(r.status_code)
