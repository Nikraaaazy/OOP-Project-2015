# import os  
# import codecs  
# filenames=os.listdir(os.getcwd())  
  
# out=file("a.gyf","a")  
# for filename in filenames: 
# 	out.write("\n") 
# 	out.write(filename.decode("gb18030").encode("utf-8"))
# out.close() 

import os  
import codecs  

dirList = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
fileList = [x.lower() + ".gyf" for x in dirList]
for directory in dirList:
	with open(directory + ".txt", 'w') as writeFile:
		os.chdir(directory)
		for readFileName in fileList:
			with open(readFileName, 'r') as readFile:
				for i in readFile:
					writeFile.write(i.decode("gb18030").encode("utf-8"))
	os.chdir("..")


# out = file("a.gyf","r")
# inFile = file("a1.gyf","w")
# for i in out:
# 	inFile.write(i.decode("gb2312").encode("utf-8"))
# inFile.close()
# out.close() 