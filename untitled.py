with open("OutputNew.txt", "w") as Out:
	with open("Output.txt", "r") as In:
		for line in In:
			if line[0] == '/':
				Out.write("/")
				Out.write(line[2:])
			else:
				Out.write(line)
