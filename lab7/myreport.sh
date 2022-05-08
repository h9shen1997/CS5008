#!/bin/bash

# Sys Report Generation

# echo "# TITLE: "
# echo " "
# echo "## Heading"
# echo "Data here"

# echo "# TITLE: System Information Report

#     ## Heading: System Information Report
#     Data here"

TITLE="System Information Report for $HOSTNAME"
CURRENT_TIME=$(date +"%x %r %Z")
TIME_STAMP="Generated $CURRENT_TIME, by $USER"

# echo "# TITLE: $TITLE

# $TIME_STAMP"

report_uptime() {
    # echo "uptime report generated"
    cat << _EOF_
System Uptime:
$(uptime)
_EOF_
    return
}

report_disk_space() {
    # echo "disk space report generated"
    cat << _EOF_
Disk Space
$(df)
_EOF_
    return
}

report_home_space() {
    # echo "home space report generated"
    cat << _EOF_
Home Space
$(du)
_EOF_
    return 
}

cat << _EOF_
TITLE: $TITLE

$TIME_STAMP

$(report_uptime)

$(report_disk_space)

$(report_home_space)
_EOF_