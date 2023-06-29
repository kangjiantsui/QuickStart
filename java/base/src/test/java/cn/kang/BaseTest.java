package cn.kang;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

class BaseTest {
    // 验证ArrayList.add()方法是否线程安全
    @Test
    public void testAdd() throws InterruptedException {
        List<Integer> list = new ArrayList<>();
        Thread thread1 = new Thread(() -> {
            for (int i = 0; i < 1000; i++) {
                list.add(i);
            }
        });
        Thread thread2 = new Thread(() -> {
            for (int i = 1000; i < 2000; i++) {
                list.add(i);
            }
        });
        thread1.start();
        thread2.start();
        // 等待所有线程执行完毕
        thread1.join();
        thread2.join();
        // 输出列表长度，如果线程安全，结果应该是2000，但实际情况可能并非如此
        System.out.println("List size: " + list.size());
        Assertions.assertThat(list).hasSize(2000);
    }
}