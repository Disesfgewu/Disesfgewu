import tkinter
import os
from pytube import YouTube

try:
    os.mkdir(path="../download")
except:
    pass

target_path = "../download"


def show():
    status["text"] = "Wait"

    url = link_get.get()
    yt = YouTube(url)

    video = yt.streams.filter(only_audio=True).first()

    out_file = video.download(output_path=target_path)

    base, ext = os.path.splitext(out_file)
    new_file = base + '.mp3'
    os.rename(out_file, new_file)

    status["text"] = "Start"


tk = tkinter.Tk()
tk.title("MP3 Download Tool")

YT_link_command = tkinter.Label(tk, text="The Youtube Link")
YT_link_command.pack()

status = tkinter.Label(tk, text="Start")
status.pack()

link_get = tkinter.Entry(tk)
link_get.pack()

Button1 = tkinter.Button(tk, text="Start", command=show)
Button1.pack()

tk.mainloop()
