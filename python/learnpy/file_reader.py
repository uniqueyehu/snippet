filename = 'pi_digits.txt'

# 逐行读取
with open(filename) as file_object:
	for line in file_object:
		print(line.rstrip())	# 删除多余的空行

# 创建一个文件各行内容的列表
with open(filename) as file_object:
	lines = file_object.readlines()

pi_string = ''
for line in lines:
	pi_string += line.strip()	# 删除字符串中的空格

print(pi_string)
print(len(pi_string))