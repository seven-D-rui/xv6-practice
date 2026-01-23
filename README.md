
# xv6 启动流程实践

## 启动流程说明
1. bootblock → bootasm.S → bootmain.c → entry.S → main()
2. 启动阶段注释已在 bootasm.S、bootmain.c、entry.S 中添加
3. bootmain.c 中打印了启动阶段信息：
   - [BOOT] enter bootmain
   - [BOOT] elf header loaded
   - [BOOT] kernel loaded
4. entry.S 标记了内核入口
5. main.c 打印了 [KERNEL] main() started

## 运行结果
系统能正常启动，QEMU 中显示启动流程信息

## 个人总结
- 理解了汇编和 C 在启动阶段的协作方式
- 掌握了 xv6 启动链路和 ELF 内核加载过程
- 学会了在关键节点插入调试信息
