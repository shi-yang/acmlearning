import Queue
N = 1005
que = Queue.Queue()
rec[1005] = Queue.Queue()
dict = {};
cas = 1
while True:
	try:
		t = int(input())
		print("Scenario #", cas)
		cas += 1
		for i in range(t):
			n = int(input())
			for j in range(n):
				x = int(input())
				dict[x] = i
		while True:
			str = input()
			if str == "ENQUEUE":
				x = int(input())
				if (!rec[dict[x]].empty()):
					que.put(dict[x])
					rec[x].put(x)
				else:
					rec[x].put(x)
					que.put(dict)

			elif str == "DEQUEUE":
				now = que.get()
				print(rec[now].get())
			else:
				break
	except EOFError:
		break