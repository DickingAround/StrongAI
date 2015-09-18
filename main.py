import strongai_dataloader
import strongai_learner
import strongai_display
if __name__ == "__main__":
	#data is a list of lists. For V1, that's a list of data-points where each one is a list of numbers that represents the grayscale of an image
	learningData,testingData = strongai_dataloader.load()
	learner = strongai_learner.learner()
	foolsResult = learner.test(testingData)	
	params = {'iterations':1000,'delta':0.00001,'display':True}
	learner.learn(learningData,params)
	smartResult = learner.test(testingData)
	#learnedResult is how closely this AI learned the 2 categories
	#Specifically the mean-square from a perfect score
	strongai_display.display(foolsResult)	
	strongai_display.display(smartResult)	
