with open("Output.txt", 'r') as inputFile:
	with open ("Vocal.txt", 'w') as vocal:
		with open ("Meaning.txt", "w") as meaning:
			for line in inputFile:
				i = 0;
				if line[0] == "/":
					vocal.write("/")
					i += 1
					while line[i] != "/":
						vocal.write(line[i])
						i += 1
					vocal.write(line[i] + "\n\n")
					i += 1
				switch = True
				for c in line[i:]:
					if c == '/':
						if switch:
							switch = False
						else:
							switch = True
					if switch:
						meaning.write(c)






