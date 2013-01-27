#!/usr/bin/python
import xml.etree.ElementTree as ET
tree = ET.parse('mtntrace.xml')
root = tree.getroot()

#for child in root:
#	print child.tag, child.attrib

hostnr=0
for host in root.findall('host'):
		
	ttlList=[]
	hostList=[]
	hostExtraList=[]

	hostnr=hostnr+1
	trace=host.find('trace')
	
	ttl=0
	for hop in trace.findall('hop'):
		ttl=ttl+1
		ttl2=hop.get("ttl")

		while (int(ttl2)>ttl):
			ttlList.append(ttl)
			if len(hostList) >0:
				hostList.append(str(hostList[-1]))
				hostExtraList.append(":"+str(ttl))
			else:
				hostList.append("Unkown")	
				hostExtraList.append(":"+str(ttl))

			#traceList.append(str(hostnr)+" "+str(ttl)+" "+str(hostnr)+":"+str(ttl))
			#traceList.append(str(hostnr)+" "+str(ttl)+" "+traceList[-1])
			ttl=ttl+1
		#if int(ttl2)>ttl:
		#	break
		ip=hop.get("ipaddr")

		ttlList.append(ttl)
		hostList.append(ip)
		hostExtraList.append("")

	for i in xrange(0,len(ttlList)): 
		print str(hostnr)+" "+str(ttlList[i])+" "+str(hostList[i])+str(hostExtraList[i])


