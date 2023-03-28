import pandas as pd
import plotly.express as px
import os
import plotly.graph_objects as go

path = "results/"

dataSource = path + "data.csv"
if os.path.exists(dataSource):
	AVG = pd.read_csv(dataSource)
else:
	print("source not available")
	exit(-1)

xAxis = "Size"
yAxis = "Time"
graphTitle = "Pior Caso"

fig = px.line(AVG, x = xAxis, y = yAxis, title = graphTitle)
fig.update_traces(line_color='purple', name='AVG', showlegend=True)

fig = go.Figure(data=fig.data)

fig.update_xaxes(title_text = xAxis)
fig.update_yaxes(title_text = yAxis)
fig.update_layout({
	'plot_bgcolor': 'rgba(255, 255, 255, 255)',
	'paper_bgcolor': 'rgba(255,255,255,255)'
})

fig.show()
fig.write_image(path + "/graph.svg")
