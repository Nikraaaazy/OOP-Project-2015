with open("Output.txt", 'w') as outputFile:
	with open("DictFile", 'r') as dictFile:
		for line in dictFile:
			marker = 0
			temp = line[0]
			for char in line:
				if char == "=" and marker == 0:
					outputFile.write("\n")
					marker = 1
				else:
					outputFile.write(char)
				temp = char
			outputFile.write("\n")
