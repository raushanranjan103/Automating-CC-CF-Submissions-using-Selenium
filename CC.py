from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager

browser=webdriver.Chrome(ChromeDriverManager().install())

browser.get("https://www.codechef.com/")

username_element=browser.find_element_by_id("edit-name")

username_element.send_keys("ENTER CODECHEF HANDLE")

password_element=browser.find_element_by_id("edit-pass")
from getpass import getpass
password_element.send_keys(getpass("ENTER CODECHEF PASSWORD"))

browser.find_element_by_id("edit-submit").click()

browser.get("https://www.codechef.com/submit/BUS")

with open("raushan.cpp",'r') as f:
    code=f.read()


code_element=browser.find_element_by_id("result")

code_element.send_keys(code)
browser.find_element_by_xpath('//*[@id="edit-language"]/option[2]').click()#c++17
browser.find_element_by_id("edit-submit").click()