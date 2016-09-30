def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return reduce(lcm, args)
if __name__ == "__main__":
	t = raw_input()
	t = int(t)
	points = {}
	points["Darrell"] = 0
	points["Sally"] = 0
	l = 0
	first = "Sally"
	second = "Darrell"
	while t:
		ques = raw_input().split()
		ans = raw_input().split()
		if l == 0:
			first = ques[0]
			second = ans[1]
			l += 1
		if ans[0] != "A":
			print "Invalid Input"
			break
		if len(ques) == 1:
			print "Invalid Input"
			break
		print ques[0] + "'s question is: " + ques[1] 
		quest = []
		question = ques[1].split(',')
		for i in question:
			quest.append(int(i))
		rightAns  =  lcmm(*quest)
		if(ans[2].isdigit()):
			InputAns = int(ans[2])
			if(InputAns%rightAns == 0):
				print "Correct Answer"
				print ans[1] + ": 10points"
				points[ans[1]] += 10
			else:
				print "Wrong Answer"
				print ans[1] + ": 0points"
		else:
			print "Question is PASSed"
			print "Answer is: " + str(rightAns)
			print ans[1] + ": 0points"
		t = t - 2
	if(t == 0):
		print "Total Points:"
		print first + ": " + str(points[first]) + "points"
		print second + ": " + str(points[second]) + "points"
		if(points["Sally"] > points["Darrell"]):
			print "Game Result: Sally is winner"
		elif(points["Sally"] < points["Darrell"]):
			print "Game Result: Darrell is winner"
		else:
			print "Game Result: Draw"
