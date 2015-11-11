import time
import sys
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select

def findPrice(driver,url, minPrice, maxPrice, idToStartWith=''):
	#Assume it's '$', uses the word 'price', appears first on the page
	#regex ^\d+(,\d{1,2})?$
	driver.get(url)
	print "got URL"
	#time.sleep(6)
	if(not idToStartWith == ''):
		elements = driver.find_elements(by=By.ID, value=idToStartWith)
	else:
		print "I'm about to fail"
	print elements
	for e in elements:
		print e.get_attribute('innerHTML')
		print "Value is: " 
		print e.get_attribute("value")
	return "done"

def main():
	print "running driver"
	driver = webdriver.Firefox()
	print "driver up"
	time.sleep(3)
	price = findPrice(driver, "http://www.homedepot.com/p/Quikrete-50-lb-Fast-Setting-Concrete-Mix-100450/100318521", 1.0, 10.0, idToStartWith='ajaxPrice')
	print price

main();
