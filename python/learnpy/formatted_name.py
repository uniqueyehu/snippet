def get_formatted_name(first_name, last_name):
	"""返回整洁的姓名"""
	full_name = first_name + ' ' + last_name
	return full_name.title()

musician = get_formatted_name('jimi', 'hendrix')
print(musician)

# 使用默认值来让实参变成可选的
def get_formatted_name_2(first_name, last_name, middle_name=''):
	"""返回整洁的姓名"""
	if middle_name:
		full_name = first_name + ' ' + middle_name + ' ' + last_name
	else:
		full_name = first_name + ' ' + last_name
	return full_name.title()

musician2 = get_formatted_name_2('john', 'hooker', 'lee')
print(musician2)
musician2 = get_formatted_name_2('jimi', 'hendrix')
print(musician2)