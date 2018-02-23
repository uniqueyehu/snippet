# 访问限制
class Student(object):
	"""docstring for Studen"""
	def __init__(self, name, score):
		self.__name = name
		self.__score = score

	def print_score(self):
		print('%s: %s' % (self.__name, self.__score))

	def get_name(self):
		return self.__name

	def get_score(self):
		return self.__score

	def set_score(self, score):
		if 0 <= score <= 100:
			self.__score = score
		else:
			raise ValueError('bad score')

bart = Student('Bart Simpson', 98)
bart.print_score()
# 私有变量不能被访问
# print(bart.__name)
# 可以使用python内部名字访问
print(bart._Student__name)

print(bart.get_score())

bart.set_score(88)
print(bart.get_score())

