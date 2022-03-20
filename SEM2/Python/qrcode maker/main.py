import qrcode
str = input("Enter link : ")
inp=input("Enter name for file :")
img = qrcode.make(f"{str}")
img.save(f"{inp}.png","PNG")
print("Thank you your qrcode has been created!")
