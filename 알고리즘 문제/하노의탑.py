class Hanoi:
	def __init__(self):
		self.count = 0
		self.arr = []

	def calc_hanoi(self, n, start_poll, destination_poll, assistant_poll):
	
		self.count = self.count + 1
	
		if n == 1:
			self.arr.append([start_poll, destination_poll])
			return self.count
		
		self.calc_hanoi(n-1, start_poll, assistant_poll, destination_poll)
	
		self.arr.append([start_poll, destination_poll])
	
		self.calc_hanoi(n-1, assistant_poll, destination_poll, start_poll)


	def main(self):
		num= int(input())
		self.calc_hanoi(num,1,3,2)
		print(self.count)
		for i in self.arr:
			print(i[0],i[1])

if __name__ == "__main__":
	hanoi = Hanoi()
	hanoi.main()

