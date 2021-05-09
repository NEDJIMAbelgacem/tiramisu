#!/usr/bin/python3

import http.client, urllib
conn = http.client.HTTPSConnection("api.pushover.net:443")
conn.request("POST", "/1/messages.json",
  urllib.parse.urlencode({
    "token": "aza1kadmi41ep7tvv1wa76y3yk52ub",
    "user": "uaq79gy4q83z9vuouj76mc3tgo81ij",
    "message": "Dibaryon execution finished",
  }), { "Content-type": "application/x-www-form-urlencoded" })
conn.getresponse()