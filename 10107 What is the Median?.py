lista = []
while True:
	try:
  		num = int(input())
  		lista.append(num)
  		lista.sort()
  		pos = int(len(lista) / 2)
  		if len(lista) % 2 == 0 :
  			print(int((lista[pos] + lista[pos-1]) / 2))
  		if len(lista) % 2 != 0 :
  			print(lista[pos])
	except EOFError:
		break
