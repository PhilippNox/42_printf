tmp = "6330914513040438074083420906343308371870292061311151946123766279817643142031003095806213018467798337581892254089291148705838414780196166290442007547130259182194886923736471756481228657080555613349113740709238710529565547689448177184264771029649970906995979989503527620583223743675641871091799987440370446582438076296316192095401360831236184517732461750503289194765492147006160448498782877865933692212003967895094931609623225607154353234592879484551979724882724850904311386011724971551169933150972899545319517094104874215735820739146361299705845915766008767109613132028967910724382012268067800835381375280165423195056083207164912944765952684874432140038995220555218636482948131221576563381908817385286973125103391149636163899670559628802792301550583338663905761607148009431409810015746949362781187804376944344197328136841925889555383961455124177689932795105209503446966203039643282343549759950490620910365096495877871886798396866009208953877797644119068110478404821704073085078097086947166854434864332765472177939388136736226495581100708244138173834310951630438999073456796595497725631587806323627063975818343757897382629344176010980438557994391186288486547551797093593823843324830873837409424699752834266170172571966052513141888834401"

glb = 0

def fun(glb):
	lin = 9
	print('\treturn ("', end='')
	while lin < 75:
		print(tmp[glb], end='')
		glb += 1
		lin += 1
	print('"')

	fill = 0
	while fill < 23:
		lin = 0
		print('\t"', end='')
		while lin < 74:
			print(tmp[glb], end='')
			glb += 1
			lin += 1
		print('"')
		fill += 1

	lin = 0
	print('\t"', end='')
	while lin < 72:
		print(tmp[glb], end='')
		glb += 1
		lin += 1
	print('");')
	return glb

glb = fun(glb)
print(glb)
glb = fun(glb)
print(glb)
glb = fun(glb)
print(glb)
