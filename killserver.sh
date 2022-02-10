#!/bin/bash

kill `ps | awk '/server/ {print $1}'`
