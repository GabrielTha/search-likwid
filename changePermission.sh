echo 1|sudo tee /proc/sys/kernel/yama/ptrace_scope
echo 0|sudo tee /proc/sys/kernel/perf_event_paranoid
