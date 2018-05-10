#! /usr/bin/env python3

# blkparse-result to count
# 这个函数主要是从result文件统计io的分布情况，即在blktrace层统计
def blkresult2count(filename, outfilename):
	# 各个区间的请求数目
	dic = {'[0-4k)':0, '[4k-8k)':0, '[8k-16k)':0, '[16k-32k)':0, \
			'[32k-128k)':0, '[128k-1m)':0, '[1m-2m)':0}
	# 请求总大小，单位为512B
	count = 0
	# 读写请总大小，单位为512B
	rw_dic = {'read':0, 'write':0}
	# 读写请求数目
	rw_count = [0, 0]

	with open(filename) as file_obj:
		for line in file_obj:
			li = line.strip().split()
			if len(li) > 4:
				# 根据result文件的分割出来的数据，选定要统计的数据
				str_type = li[2]	# 读写类型
				str_size = li[4]	# 请求大小
				size = int(str_size)
				count += size

				if size < 8:
					dic['[0-4k)'] += 1
				elif size >= 8 and size < 16:
					dic['[4k-8k)'] += 1
				elif size >= 16 and size < 32:
					dic['[8k-16k)'] += 1
				elif size >= 32 and size < 64:
					dic['[16k-32k)'] += 1
				elif size >= 64 and size < 256:
					dic['[32k-128k)'] += 1
				elif size >= 256 and size < 2048:
					dic['[128k-1m)'] += 1
				elif size >= 2048 and size < 4096:
					dic['[1m-2m)'] += 1

				if str_type == 'R' or str_type == 'RM':
					rw_dic['read'] += size
					rw_count[0] += 1
				else:
					rw_dic['write'] += size
					rw_count[1] += 1

	# 将统计的数据写入到文件
	with open(outfilename, 'w') as file_obj:
		file_obj.write('statics from blkparse:\n')
		file_obj.write('[0-4k)' + ' ' + str(dic['[0-4k)']) + '\n')
		file_obj.write('[4k-8k)' + ' ' + str(dic['[4k-8k)']) + '\n')
		file_obj.write('[8k-16k)' + ' ' + str(dic['[8k-16k)']) + '\n')
		file_obj.write('[16k-32k)' + ' ' + str(dic['[16k-32k)']) + '\n')
		file_obj.write('[32k-128k)' + ' ' + str(dic['[32k-128k)']) + '\n')
		file_obj.write('[128k-1m)' + ' ' + str(dic['[128k-1m)']) + '\n')
		file_obj.write('[1m-2m)' + ' ' + str(dic['[1m-2m)']) + '\n')
		file_obj.write('total size : ' + ' ' + str(count) + '\n')
		file_obj.write('read size : ' + str(rw_dic['read']) + ' times : ' \
						+ str(rw_count[0]) + '\n')
		file_obj.write('write size : ' + str(rw_dic['write']) + ' times : ' \
						+ str(rw_count[1]) + '\n')


# syslog to count
# 这个函数主要是根据syslog文件，统计META、DATA、NODE的读写数目和大小，在F2FS层
def syslog2count(filename, outfilename):
	# [rnums, rsize, wnums, wsize]
	# 依次为读次数、读大小、写次数、写大小
	dic = {'META-CP':[0, 0, 0, 0], 'META-SIT':[0, 0, 0, 0], 'META-NAT':[0, 0, 0, 0], \
			'META-SSA':[0, 0, 0, 0], 'DATA':[0, 0, 0, 0], 'NODE':[0, 0, 0, 0], \
			'META-FLUSH':[0, 0, 0, 0], 'OTHER':[0, 0, 0, 0]}
	# io总量，单位为512B
	count = 0

	# 元数据区的分布，对于同一块磁盘来说是在格式化时固定的
	# SATA SSD的元数据区分布
	cp_addr = 4096
	sit_addr = 12288
	nat_addr = 36864
	ssa_addr = 503808
	main_addr = 962560

	# PCIE SSD的元数据区分布
	# cp_addr = 
	# sit_addr = 
	# nat_addr = 
	# ssa_addr = 
	# main_addr = 

	with open(filename) as file_obj:
		for line in file_obj:
			li = line.strip().split()
			# print(li)
			if len(li) > 13:
				# 这里需要根据syslog文件分割的情况来定，有时候会有变化
				str_type = li[7]	# 数据类型
				str_rw = li[9]		# 读写类型
				str_addr = li[11]	# 请求地址
				str_size = li[13]	# 请求大小

				rw = int(str_rw)
				addr = int(str_addr)
				size = int(str_size)
				count += size

				if addr >= cp_addr and addr < sit_addr:
					if rw == 1:
						dic['META-CP'][0] += 1
						dic['META-CP'][1] += size
					else:
						dic['META-CP'][2] += 1
						dic['META-CP'][3] += size
				elif addr >= sit_addr and addr < nat_addr:
					if rw == 1:
						dic['META-SIT'][0] += 1
						dic['META-SIT'][1] += size
					else:
						dic['META-SIT'][2] += 1
						dic['META-SIT'][3] += size
				elif addr >= nat_addr and addr < ssa_addr:
					if rw == 1:
						dic['META-NAT'][0] += 1
						dic['META-NAT'][1] += size
					else:
						dic['META-NAT'][2] += 1
						dic['META-NAT'][3] += size
				elif addr >= ssa_addr and addr < main_addr:
					if rw == 1:
						dic['META-SSA'][0] += 1
						dic['META-SSA'][1] += size
					else:
						dic['META-SSA'][2] += 1
						dic['META-SSA'][3] += size
				elif str_type == 'DATA':
					if rw == 1:
						dic['DATA'][0] += 1
						dic['DATA'][1] += size
					else:
						dic['DATA'][2] += 1
						dic['DATA'][3] += size
				elif str_type == 'NODE':
					if rw == 1:
						dic['NODE'][0] += 1
						dic['NODE'][1] += size
					else:
						dic['NODE'][2] += 1
						dic['NODE'][3] += size
				elif str_type == 'META_FLUSH':
					if rw == 1:
						dic['META-FLUSH'][0] += 1
						dic['META-FLUSH'][1] += size
					else:
						dic['META-FLUSH'][2] += 1
						dic['META-FLUSH'][3] += size
				else:
					if rw == 1:
						dic['OTHER'][0] += 1
						dic['OTHER'][1] += size
					else:
						dic['OTHER'][2] += 1
						dic['OTHER'][3] += size

	print(dic)
	print(count)

	# 将统计结果追加写入count文件
	with open(outfilename, 'a') as file_obj:
		file_obj.write('\nMETA-CP' + ' ' + str(dic['META-CP'][0]) + ' ' \
						+ str(dic['META-CP'][1]) + ' ' + str(dic['META-CP'][2]) \
						+ ' ' + str(dic['META-CP'][3]) + '\n')
		file_obj.write('META-SIT' + ' ' + str(dic['META-SIT'][0]) + ' ' \
						+ str(dic['META-SIT'][1]) + ' ' + str(dic['META-SIT'][2]) \
						+ ' ' + str(dic['META-SIT'][3]) + '\n')
		file_obj.write('META-NAT' + ' ' + str(dic['META-NAT'][0]) + ' ' \
						+ str(dic['META-NAT'][1]) + ' ' + str(dic['META-NAT'][2]) \
						+ ' ' + str(dic['META-NAT'][3]) + '\n')
		file_obj.write('META-SSA' + ' ' + str(dic['META-SSA'][0]) + ' ' \
						+ str(dic['META-SSA'][1]) + ' ' + str(dic['META-SSA'][2]) \
						+ ' ' + str(dic['META-SSA'][3]) + '\n')
		file_obj.write('DATA' + ' ' + str(dic['DATA'][0]) + ' ' + str(dic['DATA'][1]) \
						+ ' ' + str(dic['DATA'][2]) + ' ' + str(dic['DATA'][3]) + '\n')
		file_obj.write('NODE' + ' ' + str(dic['NODE'][0]) + ' ' + str(dic['NODE'][1]) \
						+ ' ' + str(dic['NODE'][2]) + ' ' + str(dic['NODE'][3]) + '\n')
		file_obj.write('META-FLUSH' + ' ' + str(dic['META-FLUSH'][0]) + ' ' \
						+ str(dic['META-FLUSH'][1]) + ' ' + str(dic['META-FLUSH'][2]) \
						+ ' ' + str(dic['META-FLUSH'][3]) + '\n')
		file_obj.write('OTHER' + ' ' + str(dic['OTHER'][0]) + ' ' + str(dic['OTHER'][1]) \
						+ ' ' + str(dic['OTHER'][2]) + ' ' + str(dic['OTHER'][3]) + '\n')
		file_obj.write('total size : ' + ' ' + str(count) + '\n')

# 这个是用来统计F2FS下发的io分布情况
def syslogrw2count(filename, outfilename):
	dic = {'[0-4k)':0, '[4k-8k)':0, '[8k-16k)':0, '[16k-32k)':0, \
			'[32k-128k)':0, '[128k-1m)':0, '[1m-2m)':0}
	count = 0

	with open(filename) as file_obj:
		for line in file_obj:
			li = line.strip().split()
			if len(li) > 13:
				str_size = li[13]
				size = int(str_size)
				count += size

				if size < 8:
					dic['[0-4k)'] += 1
				elif size >= 8 and size < 16:
					dic['[4k-8k)'] += 1
				elif size >= 16 and size < 32:
					dic['[8k-16k)'] += 1
				elif size >= 32 and size < 64:
					dic['[16k-32k)'] += 1
				elif size >= 64 and size < 256:
					dic['[32k-128k)'] += 1
				elif size >= 256 and size < 2048:
					dic['[128k-1m)'] += 1
				elif size >= 2048 and size < 4096:
					dic['[1m-2m)'] += 1

	print(dic)
	# 追加写入到count文件中
	with open(outfilename, 'a') as file_obj:
		file_obj.write('f2fs rw size:\n')
		file_obj.write('[0-4k)' + ' ' + str(dic['[0-4k)']) + '\n')
		file_obj.write('[4k-8k)' + ' ' + str(dic['[4k-8k)']) + '\n')
		file_obj.write('[8k-16k)' + ' ' + str(dic['[8k-16k)']) + '\n')
		file_obj.write('[16k-32k)' + ' ' + str(dic['[16k-32k)']) + '\n')
		file_obj.write('[32k-128k)' + ' ' + str(dic['[32k-128k)']) + '\n')
		file_obj.write('[128k-1m)' + ' ' + str(dic['[128k-1m)']) + '\n')
		file_obj.write('[1m-2m)' + ' ' + str(dic['[1m-2m)']) + '\n')
		file_obj.write('total size : ' + ' ' + str(count) + '\n')

# 这里主要是要统计的文件result-xxxxx和syslog-xxxx
# 统计结果写入的文件count-xxxxx，注意是追加写入的
blkresult2count('/root/yh/20180508/result-nilfs2-fileserver.out', \
				'/root/yh/20180508/count-nilfs2-fileserver.out')
syslog2count('/root/yh/20180507/syslog-fio-1.out', \
			'/root/yh/20180507/count-fio-1.out')
syslogrw2count('/root/yh/20180507/syslog-fio-1.out', \
			'/root/yh/20180507/count-fio-1.out')

blkresult2count('/root/yh/20180508/result-nilfs2-mongo.out', \
				'/root/yh/20180508/count-nilfs2-mongo.out')
syslog2count('/root/yh/20180507/syslog-fio-2.out', \
			'/root/yh/20180507/count-fio-2.out')
syslogrw2count('/root/yh/20180507/syslog-fio-2.out', \
			'/root/yh/20180507/count-fio-2.out')

blkresult2count('/root/yh/20180508/result-nilfs2-varmail.out', \
				'/root/yh/20180508/count-nilfs2-varmail.out')
