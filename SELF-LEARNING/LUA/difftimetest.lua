function sleep(n)
  os.execute("sleep " .. tonumber(n))
end

time_start = os.time(os.date("*t"))
print("Time Str: " .. time_start)
sleep(5)
time_end = os.time(os.date("*t"))
print("Time End: " .. time_end)
time_dif = os.difftime(time_end, time_start)
print("Time Dif: " .. time_dif)
