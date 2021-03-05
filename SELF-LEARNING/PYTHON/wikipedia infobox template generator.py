f = open("Copy this.txt", "w")
number_of_custom_sections_per_header = 5
starting_label_per_header = [6, 23, 45, 63, 86]
data_headers = ["general","geography","culture","government","history"]
for idx,label in enumerate(data_headers):    
    for x in range(number_of_custom_sections_per_header):
        f.write("| label"+str(starting_label_per_header[idx]+x)+" = {{{"+"custom_"+label+"_label"+str(x)+"|}}}\n")
        f.write("| data"+str(starting_label_per_header[idx]+x)+" = {{{"+"custom_"+label+"_data"+str(x)+"|}}}\n\n")
    for x in range(number_of_custom_sections_per_header):
        f.write("{{{"+"custom_"+label+"_label"+str(x)+"|}}}")
        f.write("{{{"+"custom_"+label+"_data"+str(x)+"|}}}")
    f.write("\n\n\n\n")
f.close()
