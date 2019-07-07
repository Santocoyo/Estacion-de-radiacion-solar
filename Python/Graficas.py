import numpy as np
import matplotlib.pyplot as plt
import scipy as sp
from scipy import signal
import matplotlib.dates as mdates
from datetime import datetime
formato_tiempo=mdates.DateFormatter("%H:%M")
data=np.genfromtxt("ES_7.TXT.txt", names=True, delimiter=",", dtype=None, encoding=None)
date_list=list()
for i in range(0,len(data)):
    fecha_hora=data["fecha"][i]+" "+data["hora"][i]
    date_list.append(datetime.strptime(fecha_hora,"%d-%m-%Y %H:%M:%S"))

fig1, ax1 = plt.subplots()
fig1.canvas.set_window_title("Temperatura y humedad")
ax1.set_title("Temperatura y humedad")
ax1.plot(date_list,signal.medfilt(data["temperatura"],595), color="red", linestyle="dotted", linewidth=1.2, label="Temperatura")
ax1.set_xlabel("Tiempo [s]")
ax1.set_ylabel("Temperatura [°C]", color="red")
ax1.tick_params(axis="y", labelcolor="red")
ax2=ax1.twinx()
ax2.plot(date_list,signal.medfilt(data["humedad"],395), color="blue", linestyle="dashed", linewidth=1.2, label="Humedad")
ax2.set_ylabel("Humedad [%]", color="blue")
ax2.tick_params(axis="y", labelcolor="blue")
mng=plt.get_current_fig_manager()
mng.window.state("zoomed")
plt.gca().xaxis.set_major_formatter(formato_tiempo)

fig2, ax3 = plt.subplots()
fig2.canvas.set_window_title("Corriente y radiación")
ax3.set_title("Corriente y radiación")
ax3.plot(date_list,signal.medfilt(data["corriente"],295), color="brown", linestyle="dotted", linewidth=1.2, label="Corriente")
ax3.set_xlabel("Tiempo [s]")
ax3.set_ylabel("Corriente [A]", color="brown")
ax3.tick_params(axis="y", labelcolor="brown")
ax4=ax3.twinx()
ax4.plot(date_list,signal.medfilt(data["radiacion"],295),color="green", linestyle="dashed", linewidth=1.2, label="Radiación")
ax4.set_ylabel("Radiación [W/m2]", color="green")
ax4.tick_params(axis="y", labelcolor="green")
mng=plt.get_current_fig_manager()
mng.window.state("zoomed")

formato_tiempo=mdates.DateFormatter("%H:%M")
plt.gca().xaxis.set_major_formatter(formato_tiempo)
ax1.legend(loc="upper right")
ax2.legend(loc="lower right")
ax3.legend(loc="upper right")
ax4.legend(loc="lower right")
ax1.grid(color="gray", linestyle="--", linewidth=0.5)
ax3.grid(color="gray", linestyle="--", linewidth=0.5)
plt.show()
