<!doctype html>
<html>
<head>

    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css"
          integrity="sha384-9aIt2nRpC12Uk9gS9baDl411NQApFmC26EwAOH8WgZl5MYYxFfc+NcPb1dKGj7Sk"
          crossorigin="anonymous">

</head>
<body>
    <form action="request.php" method="post">
        <div class="container">
            <h1>Please describe your problem.</h1>
            <hr>

            <textarea autofocus name="problem-message" rows="6" cols="100" maxlength="350"></textarea>

            <hr>
            <button type="submit" class="btn btn-primary">Send</button>
        </div>
    </form>
</body>

</html>
