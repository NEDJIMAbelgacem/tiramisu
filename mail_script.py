#!/usr/bin/python

import smtplib

sender = 'dgx1@mail.com'
receivers = ['gb_nedjima@esi.dz']

message = """From: From Person <dgx1@mail.com>
To: To Person <gb_nedjima@esi.dz>
Subject: Your script has finished
"""

try:
   smtpObj = smtplib.SMTP('localhost')
   smtpObj.sendmail(sender, receivers, message)         
   print( "Successfully sent email" )
except SMTPException:
   print( "Error: unable to send email" )
   print e
