import strongai_dataloader

if __name__ == "__main__":
	#data is a list of lists. For V1, that's a list of data-points where each one is a list of numbers that represents the grayscale of an image
	learningData,testingData = strongai_dataloader.load()
	ai = strongai_learner.make_learner()
	foolsResult = ai.test(testingData)	
	params = {'iterations':1000,'delta':0.00001,'display':True}
	ai.learn(learningData,params)
	smartResult = ai.test(testingData)
	#learnedResult is how closely this AI learned the 2 categories
	#Specifically the mean-square from a perfect score
	displayResults(foolsResult)	
	displayResults(smartResult)	
