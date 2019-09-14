import pyrebase
from dotenv import load_dotenv
import os

load_dotenv()
DATABASE_PASSWORD = os.getenv("DATABASE_PASSWORD")

config = {
    "apiKey": "AIzaSyC1yqRCgLazzrCiNWz8hpQeYJ7cLeCgEuI",
    "authDomain": "hack-the-north-2019-64e0c.firebaseapp.com",
    "databaseURL": "https://hack-the-north-2019-64e0c.firebaseio.com",
    "storageBucket": "hack-the-north-2019-64e0c.appspot.com"
  }

firebase = pyrebase.initialize_app(config)

auth = firebase.auth()
# auth.create_user_with_email_and_password(os.getenv("DATABASE_USER"), os.getenv("DATABASE_PASSWORD"))

user = auth.sign_in_with_email_and_password(os.getenv("DATABASE_USER"), os.getenv("DATABASE_PASSWORD"))

db = firebase.database()

data = {
    "name": "Mortimer 'Morty' Smith"
}

results = db.child("beats").push(data, user['idToken'])
