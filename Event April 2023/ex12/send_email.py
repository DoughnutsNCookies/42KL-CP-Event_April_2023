import smtplib, ssl, getpass
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication

password		= getpass.getpass("Password: ")
PORT			= 465
SMTP_SERVER		= "smtp.gmail.com"
SENDER_EMAIL	= "42schuah@gmail.com"
RECEIVER_EMAIL	= "undergroundneet@gmail.com"
SUBJECT			= "Test from Python"
BODY			= "This message is sent from Python."
FILENAME		= "send_email.py"

try:
	with open(FILENAME, "rb") as attachment:
		part = MIMEApplication(attachment.read(), Name=FILENAME)
		part['Content-Disposition'] = f'attachment; FILENAME="{FILENAME}"'

	message = MIMEMultipart()
	message["From"] = SENDER_EMAIL
	message["To"] = RECEIVER_EMAIL
	message["Subject"] = SUBJECT
	message.attach(MIMEText(BODY))
	message.attach(part)

	context = ssl.create_default_context()
	with smtplib.SMTP_SSL(SMTP_SERVER, PORT, context=context) as server:
		server.login(SENDER_EMAIL, password)
		server.sendmail(SENDER_EMAIL, RECEIVER_EMAIL, message.as_string())
	print("Email sent successfully")
except Exception as e:
	print(f"Error: Unable to send email: {e}")