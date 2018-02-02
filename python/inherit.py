class Animal(object):
	def run(self):
		print('Animal is running...')

class Dog(Animal):
	def run(self):
		print('Dog is running...')

	def eat(self):
		print('Eating meat...')

class Cat(object):
	def run(self):
		print('starting...')

def run_twice(animal):
	animal.run()
	animal.run()


dog = Dog()
dog.run()
dog.eat()

# 只要对象有run方法即可
run_twice(Dog())
run_twice(Cat())