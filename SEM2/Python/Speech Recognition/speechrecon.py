import time
import playsound
import speech_recognition as sr
import webbrowser
import pywhatkit
from time import ctime
import os
import random
from gtts import gTTS


def there_exists(terms):
    for term in terms:
        if term in voice_data:
            return True
def alexis_speak(audio_string):
    tts=gTTS(text=audio_string,lang="en")
    r=random.randint(1,1000000)
    audio_file='audio-'+str(r)+'.mp3'
    tts.save(audio_file)
    playsound.playsound(audio_file)
    print(audio_string)
    os.remove(audio_file)

def capture_audio():

    r = sr.Recognizer()

    with sr.Microphone() as source:
        audio = r.listen(source)
        voice_data=''

        try:
            voice_data=r.recognize_google(audio)
        except sr.UnknownValueError:
            alexis_speak("Sorry,I did not get that.")
        except sr.RequestError:
            alexis_speak("Server Down")

    return voice_data.upper()

def respond(voice_data):
    if there_exists(["WHAT IS YOUR NAME","NAME","TELL ME YOUR NAME"]):
        alexis_speak("My name is Alexis")

    if there_exists(["WHAT TIME IS IT","WHAT IS THE TIME",'TIME']):
        alexis_speak(ctime())

    if there_exists(["SEARCH","FIND"]):
        alexis_speak("What do you want to search?")
        search=capture_audio()
        url="https://www.google.com/search?q="+search
        webbrowser.get().open(url)
        alexis_speak("Here is the result for "+search)
    if there_exists(["PLAY"]):
        alexis_speak("What do you want to play?")
        play=capture_audio()
        pywhatkit.playonyt(play)
    if there_exists(["EXIT","GET LOST","THANK YOU","BYE",'BYE BYE']) :
        alexis_speak("Thank you,i'll go now")
        exit()


time.sleep(1)
alexis_speak("How can i help you with?")
while 1:
    voice_data=capture_audio()
    respond(voice_data)