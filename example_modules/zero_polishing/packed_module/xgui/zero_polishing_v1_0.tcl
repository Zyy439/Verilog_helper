# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  set Page_0 [ipgui::add_page $IPINST -name "Page 0"]
  #Adding Group
  set width_setting [ipgui::add_group $IPINST -name "width setting" -parent ${Page_0} -display_name {Width Setting}]
  ipgui::add_param $IPINST -name "WIDTH_OUTPUT" -parent ${width_setting}
  ipgui::add_param $IPINST -name "WIDTH_INPUT" -parent ${width_setting}

  #Adding Group
  set Other_Option [ipgui::add_group $IPINST -name "Other Option" -parent ${Page_0}]
  set_property tooltip {Other Option} ${Other_Option}
  ipgui::add_static_text $IPINST -name "discription" -parent ${Other_Option} -text {The Input data will be allcolated into highbits of the output data if this checkbox is enabled}
  ipgui::add_param $IPINST -name "HIGHBITS_ALLOCATE" -parent ${Other_Option} -widget comboBox
  ipgui::add_static_text $IPINST -name "discrption2" -parent ${Other_Option} -text {this checkbox will allow you to fill 1 in the vacant bits}
  ipgui::add_param $IPINST -name "FILL_BIT1" -parent ${Other_Option} -widget comboBox



}

proc update_PARAM_VALUE.FILL_BIT1 { PARAM_VALUE.FILL_BIT1 } {
	# Procedure called to update FILL_BIT1 when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.FILL_BIT1 { PARAM_VALUE.FILL_BIT1 } {
	# Procedure called to validate FILL_BIT1
	return true
}

proc update_PARAM_VALUE.HIGHBITS_ALLOCATE { PARAM_VALUE.HIGHBITS_ALLOCATE } {
	# Procedure called to update HIGHBITS_ALLOCATE when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.HIGHBITS_ALLOCATE { PARAM_VALUE.HIGHBITS_ALLOCATE } {
	# Procedure called to validate HIGHBITS_ALLOCATE
	return true
}

proc update_PARAM_VALUE.WIDTH_INPUT { PARAM_VALUE.WIDTH_INPUT } {
	# Procedure called to update WIDTH_INPUT when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.WIDTH_INPUT { PARAM_VALUE.WIDTH_INPUT } {
	# Procedure called to validate WIDTH_INPUT
	return true
}

proc update_PARAM_VALUE.WIDTH_OUTPUT { PARAM_VALUE.WIDTH_OUTPUT } {
	# Procedure called to update WIDTH_OUTPUT when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.WIDTH_OUTPUT { PARAM_VALUE.WIDTH_OUTPUT } {
	# Procedure called to validate WIDTH_OUTPUT
	return true
}


proc update_MODELPARAM_VALUE.WIDTH_INPUT { MODELPARAM_VALUE.WIDTH_INPUT PARAM_VALUE.WIDTH_INPUT } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.WIDTH_INPUT}] ${MODELPARAM_VALUE.WIDTH_INPUT}
}

proc update_MODELPARAM_VALUE.WIDTH_OUTPUT { MODELPARAM_VALUE.WIDTH_OUTPUT PARAM_VALUE.WIDTH_OUTPUT } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.WIDTH_OUTPUT}] ${MODELPARAM_VALUE.WIDTH_OUTPUT}
}

proc update_MODELPARAM_VALUE.HIGHBITS_ALLOCATE { MODELPARAM_VALUE.HIGHBITS_ALLOCATE PARAM_VALUE.HIGHBITS_ALLOCATE } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.HIGHBITS_ALLOCATE}] ${MODELPARAM_VALUE.HIGHBITS_ALLOCATE}
}

proc update_MODELPARAM_VALUE.FILL_BIT1 { MODELPARAM_VALUE.FILL_BIT1 PARAM_VALUE.FILL_BIT1 } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.FILL_BIT1}] ${MODELPARAM_VALUE.FILL_BIT1}
}

